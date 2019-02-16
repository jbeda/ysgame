#include "ArrayMap.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <stdio.h>
#include <vector>
#include <fstream>

#include <nlohmann/json.hpp>

ArrayMap::ArrayMap() {
	this->LoadMap();
}

ArrayMap::~ArrayMap() {
	for (auto t : this->textures) {
		SDL_DestroyTexture(t);
	}
}

struct JsonMap {
	int tileRows;
	int tileCols;
	int tileSize;
	std::vector<std::string> textures;
	std::vector<std::vector<int>> tiles;
	std::vector<std::vector<int>> hitBoxes;
};

void from_json(const nlohmann::json& j, JsonMap& m) {
	m.tileCols = j["tilecols"].get<int>();
	m.tileRows = j["tilerows"].get<int>();
	m.tileSize = j["tilesize"].get<int>();
	m.tiles = j["tiles"].get<std::vector<std::vector<int>>>();
	m.hitBoxes = j["hitboxes"].get<std::vector<std::vector<int>>>();
	m.textures = j["textures"].get<std::vector<std::string>>();
}

void ArrayMap::LoadMap() {
	std::ifstream i("maps\\map.json");

	// Parse the json object into generic representation
	nlohmann::json j;
	i >> j;

	// Convert that to strongly typed structure.
	JsonMap m = j;

	// Pull data out in more useful way
	this->tileCols = m.tileCols;
	this->tileRows = m.tileRows;
	this->tileSize = m.tileSize;
	this->tiles = m.tiles;
	this->hbValues = m.hitBoxes;

	// Load up the textures
	for (auto tname : m.textures) {
		auto t = TextureManager::LoadTexture(tname.c_str());
		this->textures.push_back(t);
	}
}

void ArrayMap::DrawMap() {
	int type;
	SDL_Rect src, dest;

	src.w = src.h = dest.w = dest.h = this->tileSize;
	src.x = src.y = dest.x = dest.y = 0;

	for (auto r = 0; r < this->tileRows; r++) {
		for (auto c = 0; c < this->tileCols; c++) {
			dest.x = c * this->tileSize;
			dest.y = r * this->tileSize;
			auto tileTexture = this->tiles[r][c];
			if (tileTexture < this->textures.size()) {
				TextureManager::Draw(this->textures[tileTexture], src, dest);
			} else {
				printf("ERROR: incorrect tile code in map array");
			}
		}
	}
}

bool ArrayMap::IsOutOfBounds(const SDL_Rect& r) {
	// Make sure that we aren't off the edge of the map
	if (r.x < 0 || r.y < 0
		|| r.x + r.w > this->tileCols*this->tileSize
		|| r.y + r.h > this->tileRows*this->tileSize) {
		return true;
	}

	// Check to make sure we aren't overlapping with a barriar.
	// We do this by getting each of the bounding corners of
	// the incoming rect and checking if they are inside a map
	// barrier tile.
	if (this->IsMapBarrierAtCoord(r.x, r.y)) {
		return true;
	}
	if (this->IsMapBarrierAtCoord(r.x+r.w, r.y)) {
		return true;
	}
	if (this->IsMapBarrierAtCoord(r.x, r.y+r.h)) {
		return true;
	}
	if (this->IsMapBarrierAtCoord(r.x+r.w, r.y+r.h)) {
		return true;
	}

	return false;
}

// Check to see if a coordinate is inside a tile marked as a
// map barrier.
bool ArrayMap::IsMapBarrierAtCoord(int pixelX, int pixelY) {
	// Do simple integer division to translate a pixel dimension
	// to a tile dimension.  This will discard/truncate any remainder.
	int tileX = pixelX / this->tileSize;
	int tileY = pixelY / this->tileSize;
	if (this->hbValues[tileY][tileX]) {
		return true;
	}
	return false;
}
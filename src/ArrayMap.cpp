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

	this->hitboxes.resize(20);
	for (auto r = 0; r < 20; r++) {
		auto& v = this->hitboxes[r];
		for (auto c = 0; c < 20; c++) {
			bool s = this->hbValues[r][c];
			v.push_back(std::make_unique<TileHitBox>(r, c, s));
		}
	}
	this->src.w = this->src.h = this->dest.w = this->dest.h = 32;
	this->src.x = this->src.y = this->dest.x = this->dest.y = 0;
}
ArrayMap::~ArrayMap() {
	for (auto t : this->textures) {
		SDL_DestroyTexture(t);
	}
}

struct JsonMap {
	int tileRows;
	int tileCols;
	std::vector<std::string> textures;
	std::vector<std::vector<int>> tiles;
	std::vector<std::vector<int>> hitBoxes;
};

void from_json(const nlohmann::json& j, JsonMap& m) {
	m.tileCols = j["tilecols"].get<int>();
	m.tileRows = j["tilerows"].get<int>();
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
	for (auto r = 0; r < 20; r++) {
		for (auto c = 0; c < 20; c++) {
			// Render & Update map hitboxes
			this->hitboxes[r][c]->Update();
			this->hitboxes[r][c]->Render();
			this->dest.x = c * 32;
			this->dest.y = r * 32;
			auto tileTexture = this->tiles[r][c];
			if (tileTexture < this->textures.size()) {
				TextureManager::Draw(this->textures[tileTexture], this->src, this->dest);
			} else {
				printf("ERROR: incorrect tile code in map array");
			}
		}
	}
}

bool ArrayMap::IsMapBarrierAtCoord(int pixelX, int pixelY) {
	ArrayMap* am = (ArrayMap*)gGame->getMap();
	printf("Looking at pixel %d, %d\n", pixelX, pixelY);
	printf("  Looking at tile %d, %d\n", pixelX / 32, pixelY / 32);
	TileHitBox* hb = (*am->getHitBoxes())[pixelY / 32][pixelX / 32].get();
	printf("  solid? %d\n", hb->IsSolid());
	return hb->IsSolid();
}
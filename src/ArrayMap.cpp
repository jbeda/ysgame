#include "ArrayMap.hpp"
#include "TextureManager.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <stdio.h>
#include <vector>
#include <fstream>

#include <nlohmann/json.hpp>

#define DIRT 0
#define GRASS 1
#define WATER 2
#define STONE 3
#define STONE_BACKGROUND 4

ArrayMap::ArrayMap() {
	this->dirt = TextureManager::LoadTexture("dirt.png");
	this->grass = TextureManager::LoadTexture("grass.png");
	this->water = TextureManager::LoadTexture("water.png");
	this->stone = TextureManager::LoadTexture("stone.png");
	this->stonebg = TextureManager::LoadTexture("stonebg.png");
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
	SDL_DestroyTexture(this->water);
	SDL_DestroyTexture(this->dirt);
	SDL_DestroyTexture(this->grass);
	SDL_DestroyTexture(this->stonebg);
	SDL_DestroyTexture(this->stone);
}

struct JsonMap {
	int tileRows;
	int tileCols;
	std::vector<std::vector<int>> tiles;
	std::vector<std::vector<int>> hitBoxes;
};

void from_json(const nlohmann::json& j, JsonMap& m) {
	m.tileCols = j["tilecols"].get<int>();
	m.tileRows = j["tilerows"].get<int>();
	m.tiles = j["tiles"].get<std::vector<std::vector<int>>>();
	m.hitBoxes = j["hitboxes"].get<std::vector<std::vector<int>>>();
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
			type = this->tiles[r][c];
			switch (type) {
			case DIRT:
				TextureManager::Draw(this->dirt, this->src, this->dest);
				break;
			case GRASS:
				TextureManager::Draw(this->grass, this->src, this->dest);
				break;
			case WATER:
				TextureManager::Draw(this->water, this->src, this->dest);
				break;
			case STONE:
				TextureManager::Draw(this->stone, this->src, this->dest);
				break;
			case STONE_BACKGROUND:
				TextureManager::Draw(this->stonebg, this->src, this->dest);
				break;
			default:
				printf("ERROR: incorrect tile code in map array");
				break;
			}
		}
	}
}
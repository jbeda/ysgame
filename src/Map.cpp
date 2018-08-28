#include "Map.hpp"
#include "TextureManager.hpp"
#include <stdio.h>
#define DIRT 0
#define GRASS 1
#define WATER 2
#define STONE 3
#define STONE_BACKGROUND 4
int lvl1[20][20] = {
    {4, 4, 4, 3, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1},
    {3, 4, 4, 4, 3, 0, 0, 1, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 3, 4, 4, 4, 3, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 3, 4, 4, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 3, 4, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
Map::Map() {
    this->dirt = TextureManager::LoadTexture("dirt.png");
    this->grass = TextureManager::LoadTexture("grass.png");
    this->water = TextureManager::LoadTexture("water.png");
    this->stone = TextureManager::LoadTexture("stone.png");
    this->stonebg = TextureManager::LoadTexture("stonebg.png");
    this->LoadMap(lvl1);
    this->src.w = this->src.h = this->dest.w = this->dest.h = 32;
    this->src.x = this->src.y = this->dest.x = this->dest.y = 0;
}
Map::~Map() {
    SDL_DestroyTexture(this->water);
    SDL_DestroyTexture(this->dirt);
    SDL_DestroyTexture(this->grass);
}
void Map::LoadMap(int map[20][20]) {
    for (auto r = 0; r < 20; r++) {
        for (auto c = 0; c < 20; c++) {
            this->map[r][c] = map[r][c];
        }
    }
}
void Map::DrawMap() {
    int type;
    for (auto r = 0; r < 20; r++) {
        for (auto c = 0; c < 20; c++) {
            this->dest.x = c * 32;
            this->dest.y = r * 32;
            type = this->map[r][c];
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
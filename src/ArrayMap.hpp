#ifndef ARRAYMAP_HPP
#define ARRAYMAP_HPP
#include <SDL.h>
#include "Map.hpp"
#include <vector>
#include "util/debugging/notif.h"
#include "util/include.h"
#include "GameObject.hpp"
#include "Game.hpp"
#include "Player.hpp"

class TileHitBox : public GameObject {
public:
	TileHitBox(int r, int c, bool solid) : GameObject(NULL, c * 32, r * 32) { this->solid = solid; }
	void Update() {
		if (this->solid) {
			if (this->Collided(Plane::X, *gGame->getPlr()) && this->Collided(Plane::Y, *gGame->getPlr())) {
				//gGame->getPlr()->getLocation()->x++;
				char row[128], col[128];
				itoa((this->destRect.y / 32), row, 10);
				itoa((this->destRect.x / 32), col, 10);
				DebugMessage(("player collided; row: " + std::string(row) + ", col: " + std::string(col)).c_str());
			}
		}
	}
	void Render() {
		SDL_RenderDrawRect(gGame->renderer, &this->destRect);
	}
private:
	bool solid;
};
class ArrayMap : public Map {
public:
	ArrayMap();
	~ArrayMap();
	void LoadMap();
	void DrawMap();
private:
	int tileRows = 0;
	int tileCols = 0;

	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	SDL_Texture* stone;
	SDL_Texture* stonebg;
	std::vector<std::vector<int>> tiles;
	std::vector<std::vector<int>> hbValues;
	std::vector<std::vector<std::unique_ptr<TileHitBox>>> hitboxes;
};

#endif
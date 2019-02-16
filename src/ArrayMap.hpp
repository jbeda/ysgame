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

class ArrayMap : public Map {
public:
	ArrayMap();
	~ArrayMap();
	void LoadMap();
	void DrawMap();
	bool IsOutOfBounds(const SDL_Rect& r) override;
private:
	int tileRows = 0;
	int tileCols = 0;
	int tileSize = 0;

	std::vector<SDL_Texture*> textures;
	std::vector<std::vector<int>> tiles;
	std::vector<std::vector<int>> hbValues;

	bool ArrayMap::IsMapBarrierAtCoord(int pixelX, int pixelY);
};

#endif
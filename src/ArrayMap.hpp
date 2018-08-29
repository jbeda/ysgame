#ifndef ARRAYMAP_HPP
#define ARRAYMAP_HPP
#include <SDL.h>
#include "Map.hpp"
#include <vector>
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
};

#endif
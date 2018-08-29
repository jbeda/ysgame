#ifndef ARRAYMAP_HPP
#define ARRAYMAP_HPP
#include <SDL.h>
#include "Map.hpp"
class ArrayMap : public Map {
public:
    ArrayMap();
    ~ArrayMap();
    void LoadMap(int map[20][20]);
    void DrawMap();
private:
    SDL_Rect src, dest;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    SDL_Texture* stone;
    SDL_Texture* stonebg;
    int map[20][25];
};

#endif
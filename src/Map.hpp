#ifndef MAP_HPP
#define MAP_HPP
#include <SDL.h>
class Map {
public:
    Map();
    ~Map();
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
#ifndef MAP_HPP
#define MAP_HPP

#include <SDL.h>
#include <string>
#include <vector>

struct Tile {
    int tile = -1;
    int flipX = false;
    int rot = 0;
};

struct TileLayer {
    // This the 2D set of tiles mapped into a 1D array.
    // The index is calculated by:
    //   (your current row index * number of columns) + your current column index
    std::vector<Tile> tiles;

    std::string name;
    int number;

    bool hide = false;
    bool solid = false;
};

class Map {
public:
    Map(std::string& mapName);
    ~Map();

    void DrawMap();

private:
    void LoadMap(std::string& mapName);
    int TileIndexFromRC(int col, int row);
    void DrawTile(Tile& t, SDL_Rect& dest);

    SDL_Texture* tileset;

    int rows = 0;
    int cols = 0;
    int tilewidth = 0;
    int tileheight = 0;

    std::vector<TileLayer> layers;
};

#endif

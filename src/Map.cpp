#include "Map.hpp"
#include "TextureManager.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>

#include "nlohmann/json.hpp"

struct JsonTile
{
    int index = 0;
    int x = 0;
    int y = 0;
    int tile = 0;
    int flipX = false;
    int rot = 0;
};

struct JsonLayer
{
    std::string name;
    int number = 0;

    std::vector<JsonTile> tiles;
};

struct JsonMapData
{
    int tileswide = 0;
    int tileshigh = 0;
    int tilewidth = 0;
    int tileheight = 0;

    std::vector<JsonLayer> layers;
};
#define JSON_VALIDATE_REQUIRED(j, field, eval_fn) do {                             \
    if (j.count(#field) == 0) {                                                    \
        throw std::invalid_argument("missing required field \"" #field "\"");      \
    } else if (!j[#field].eval_fn()) {                                             \
        throw std::invalid_argument("\"" #field "\" failed " #eval_fn "() check"); \
    }                                                                              \
} while (false)

void from_json(const nlohmann::json& j, JsonTile& t) {
    JSON_VALIDATE_REQUIRED(j, index, is_number);
    JSON_VALIDATE_REQUIRED(j, x, is_number_unsigned);
    JSON_VALIDATE_REQUIRED(j, y, is_number_unsigned);
    JSON_VALIDATE_REQUIRED(j, tile, is_number);
    JSON_VALIDATE_REQUIRED(j, flipX, is_boolean);
    JSON_VALIDATE_REQUIRED(j, rot, is_number);

    t.index = j["index"].get<int>();
    t.x = j["x"].get<int>();
    t.y = j["y"].get<int>();
    t.tile = j["tile"].get<int>();
    t.flipX = j["flipX"].get<bool>();
    t.rot = j["rot"].get<int>();
}

void from_json(const nlohmann::json& j, JsonLayer& l) {
    JSON_VALIDATE_REQUIRED(j, name, is_string);
    JSON_VALIDATE_REQUIRED(j, number, is_number_unsigned);
    JSON_VALIDATE_REQUIRED(j, tiles, is_array);

    l.name = j["name"].get<std::string>();
    l.number = j["number"].get<int>();
    l.tiles = j["tiles"].get<std::vector<JsonTile>>();
}

void from_json(const nlohmann::json& j, JsonMapData& m) {
    JSON_VALIDATE_REQUIRED(j, tileswide, is_number_unsigned);
    JSON_VALIDATE_REQUIRED(j, tileshigh, is_number_unsigned);
    JSON_VALIDATE_REQUIRED(j, tilewidth, is_number_unsigned);
    JSON_VALIDATE_REQUIRED(j, tileheight, is_number_unsigned);
    JSON_VALIDATE_REQUIRED(j, layers, is_array);

    m.tileswide = j["tileswide"].get<int>();
    m.tileshigh = j["tileshigh"].get<int>();
    m.tilewidth = j["tilewidth"].get<int>();
    m.tileheight = j["tileheight"].get<int>();
    m.layers = j["layers"].get<std::vector<JsonLayer>>();
}

Map::Map(std::string& mapName) {
    this->tileset = TextureManager::LoadTexture(( mapName + ".png").c_str());
    this->LoadMap("assets\\" + mapName + ".json");
}

Map::~Map() {
    SDL_DestroyTexture(this->tileset);

}
void Map::LoadMap(std::string& mapName) {
    std::ifstream i(mapName);

    // Parse the json object into generic representation
    nlohmann::json j;
    i >> j;

    // Convert that to strongly typed structure.
    JsonMapData m = j;

    // Pull data out in more useful way
    this->cols = m.tileswide;
    this->rows = m.tileshigh;
    this->tileheight = m.tileheight;
    this->tilewidth = m.tilewidth;

    this->layers.resize(m.layers.size());

    for (auto idxLayer = 0; idxLayer < m.layers.size(); idxLayer++) {
        auto& il = m.layers[idxLayer];
        auto& ol = this->layers[il.number];

        ol.name = il.name;
        ol.number = il.number;

        if (ol.name == "bounds") {
            ol.hide = true;
            ol.solid = true;
        }

        ol.tiles.resize(this->cols * this->rows);

        for (auto& it : il.tiles) {
            Tile& ot = ol.tiles[this->TileIndexFromRC(it.x, it.y)];
            ot.tile = it.tile;
            ot.flipX = it.flipX;
            ot.rot = it.rot;
        }
    }

    std::sort(std::begin(this->layers), std::end(this->layers),
        [](TileLayer& a, TileLayer& b) -> bool { return a.number > b.number; });
}

int Map::TileIndexFromRC(int col, int row)
{
    return row * this->cols + col;
}

void Map::DrawTile(Tile& t, SDL_Rect & dest)
{
    if (t.tile < 0) {
        return;
    }

    // We need to figure out the source rect based on the tile index.
    SDL_Rect src;
    src.w = this->tilewidth;
    src.h = this->tileheight;
    src.x = (t.tile % 8) * src.w;
    src.y = (t.tile / 8) * src.h;

    TextureManager::Draw(this->tileset, src, dest, t.rot*90, t.flipX ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Map::DrawMap() {
    SDL_Rect dest;
    dest.w = this->tilewidth;
    dest.h = this->tileheight;

    for (auto r = 0; r < this->rows; r++) {
        dest.y = r * dest.h;
        for (auto c = 0; c < this->cols; c++) {
            dest.x = c * dest.w;

            for (auto& l : this->layers) {
                if (l.hide) continue;

                auto& t = l.tiles[this->TileIndexFromRC(c, r)];
                this->DrawTile(t, dest);
            }
        }
    }
}
#pragma once

// Pure virtual base class for the map
class Map {
public:
    virtual ~Map() {};

    virtual void DrawMap() = 0;
};

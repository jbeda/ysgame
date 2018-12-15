#pragma once
#define PIX2TILE(p) p/32
#define TILE2PIX(t) t*32
// Pure virtual base class for the map
class Map {
public:
	virtual ~Map() {};

	virtual void DrawMap() = 0;

	virtual bool IsMapBarrierAtCoord(int pixelX, int pixelY) = 0;
};

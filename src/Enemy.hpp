#pragma once
#include "GameObject.hpp"
class Enemy : public GameObject {
public:
	Enemy(int x, int y) : GameObject("Enemy.png", x, y) { };
	void Update();
};
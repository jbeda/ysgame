#pragma once
#include "SimpleGameObject.hpp"
class Enemy : public SimpleGameObject {
public:
	Enemy(int x, int y) : SimpleGameObject("Enemy.png", x, y, EEnemy) { };
	void Update();
	void Kill() { dead = true; }
};
#pragma once
#include "RapidKnife.hpp"
using vec2 = Vector2f;
class HomingKnife : public RapidKnife {
public:
	void Update() override {
		Enemy* closest_enemy = this->FindClosestEnemy();
		if (!closest_enemy)
			return;
		if (this->destRect.x < closest_enemy->getLocation().x)
			this->destRect.x++;
		else if (this->destRect.x > closest_enemy->getLocation().x)
			this->destRect.x--;
		if (this->destRect.y < closest_enemy->getLocation().y)
			this->destRect.y++;
		else if (this->destRect.y > closest_enemy->getLocation().y)
			this->destRect.y--;
		if (this->Collided(Plane::X, *closest_enemy) && this->Collided(Plane::Y, *closest_enemy)) {
			closest_enemy->hurt(1);
			this->dead = true;
		}
	}
};
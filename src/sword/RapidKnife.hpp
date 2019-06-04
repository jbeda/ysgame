#pragma once
#include "Sword.hpp"
#include "../Player.hpp"
#include "../Game.hpp"
#include <memory>
#include "../Vector2D.hpp"
#include "../util/debugging/notif.h"
#include "Enemy.hpp"
class RapidKnife : public Sword {
public:
	RapidKnife() : Sword() {
		this->destRect.y = gGame->getPlr()->getLocation().y + 5;
		if (gGame->getPlr()->getRenderFlip() == SDL_FLIP_NONE)
			this->destRect.x = gGame->getPlr()->getLocation().x + 20;
		else
			this->destRect.x = gGame->getPlr()->getLocation().x - 7;
	}
	virtual void Update() {
		if (this->rotation == 135 || this->rotation == -135) {
			this->ResetSwing();
			this->dead = true;
		}
		if (this->swinging) {
			if (gGame->getPlr()->getRenderFlip() == SDL_FLIP_NONE) {
				this->Rotate(3);
				this->destRect.x += 1;
			}
			else {
				this->Rotate(-3);
				this->destRect.x -= 1;
			}
			this->destRect.y += 0.5;
		}
		Enemy* closest_enemy = this->FindClosestEnemy();
		if (!closest_enemy)
			return;
		if (this->Collided(Plane::X, *closest_enemy) && this->Collided(Plane::Y, *closest_enemy)) {
			closest_enemy->hurt(1);
			this->dead = true;
		}
	}
protected:
	Enemy* FindClosestEnemy() {
		float closest_dist = INFINITY;
		Enemy* closest_enemy = NULL;
		auto knifeLoc = this->getLocation();
		for (std::unique_ptr<GameObject>& object_ptr : gGame->getObjectList()) {
			auto enemy = object_ptr->AsEnemy();
			if (enemy != NULL) {
				auto enemyLoc = enemy->getLocation();
				auto dist = enemyLoc.Sub(knifeLoc).Mag();
				if (dist < closest_dist) {
					closest_dist = dist;
					closest_enemy = enemy;
				}
			}
		}
		return closest_enemy;
	}
};
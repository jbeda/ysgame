#pragma once
#include "Sword.hpp"
#include "../Player.hpp"
#include "../Game.hpp"
#include "../util/debugging/notif.h"
class RapidKnife : public Sword {
public:
	RapidKnife() : Sword() {
		this->destRect.y = gGame->getPlr()->getLocation()->y + 5;
		if (gGame->getPlr()->getRenderFlip() == SDL_FLIP_NONE)
			this->destRect.x = gGame->getPlr()->getLocation()->x + 20;
		else
			this->destRect.x = gGame->getPlr()->getLocation()->x - 7;
	}
	void Update() {
		if (rotation == 135 || rotation == -135) {
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
	}
};
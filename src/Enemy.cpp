#include "Enemy.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "util/debugging/notif.h"
#include "util/include.h"
#include "util/numbers.h"
void Enemy::Update() {
	auto plrLoc = gGame->getPlr()->getLocation();
	if (this->destRect.x < plrLoc.x) {
		this->destRect.x++;
		this->currentFlip = SDL_FLIP_NONE;
	} else if (this->destRect.x > plrLoc.x) {
		this->destRect.x--;
		this->currentFlip = SDL_FLIP_HORIZONTAL;
	}
	if (this->destRect.y < plrLoc.y) {
		this->destRect.y++;
	} else if (this->destRect.y > plrLoc.y) {
		this->destRect.y--;
	}
	bool x = this->Collided(Plane::X, *(gGame->getPlr()->sw));
	bool y = this->Collided(Plane::Y, *(gGame->getPlr()->sw));
	if ((x && y) && gGame->getPlr()->sw->IsSwinging()) {
		this->hurt(1);
		// reset the throwing knife
		gGame->getPlr()->sw->ResetSwing();
	}
	if (this->hp <= 0)
		this->dead = true;
}
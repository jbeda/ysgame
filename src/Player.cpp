#include "Game.hpp"
#include "Player.hpp"
#include "util/debugging/notif.h"
#include "ArrayMap.hpp"
const int moveIncrement = 2;
#define HitBoxArray (*((ArrayMap*)gGame->getMap())->getHitBoxes())
void Player::Update() {
	auto move = gGame->getInput()->GetMove();
	
	if (move.x == XMove::XLeft) {
		this->destRect.x -= moveIncrement;
		this->currentFlip = SDL_FLIP_HORIZONTAL;
		if (gGame->getMap()->IsOutOfBounds(this->destRect))
			this->destRect.x += moveIncrement;
	} else if (move.x == XMove::XRight) {
		this->destRect.x += moveIncrement;
		this->currentFlip = SDL_FLIP_NONE;
		if (gGame->getMap()->IsOutOfBounds(this->destRect))
			this->destRect.x -= moveIncrement;
	}

	if (move.y == YMove::YUp) {
		this->destRect.y -= moveIncrement;
		if (gGame->getMap()->IsOutOfBounds(this->destRect))
			this->destRect.y += moveIncrement;
	} else if (move.y == YMove::YDown) {
		this->destRect.y += moveIncrement;
		if (gGame->getMap()->IsOutOfBounds(this->destRect))
			this->destRect.y -= moveIncrement;
	}

	this->sw->Update();
}

void Player::Render() {
	SimpleGameObject::Render();
	this->sw->Render();
}

void Player::AddEffect(Weapon* effect) {
	// Delete any existing effect
	delete this->effect;

	DebugMessage(("Aquired effect: " + EffectToStr(effect->getEnumeration())).c_str());
	this->effect = effect;
}

void Player::ClearEffect() { 
	delete this->effect;
	this->effect = NULL; 
}

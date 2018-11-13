#include "Game.hpp"
#include "Player.hpp"
#include "util/debugging/notif.h"

const int moveIncrement = 2;

void Player::Update() {
	auto move = gGame->getInput()->GetMove();

	if (move.x == XMove::XLeft) {
		this->destRect.x -= moveIncrement;
		this->currentFlip = SDL_FLIP_HORIZONTAL;
	} else if (move.x == XMove::XRight) {
		this->destRect.x += moveIncrement;
		this->currentFlip = SDL_FLIP_NONE;
	}

	if (move.y == YMove::YUp) {
		this->destRect.y -= moveIncrement;
	} else if (move.y == YMove::YDown) {
		this->destRect.y += moveIncrement;
	}

	this->sw->Update();
}

void Player::Render() {
	GameObject::Render();
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

#include "Player.hpp"
#include "Controller.hpp"
#include "Keyboard.hpp"
#include "util/debugging/notif.h"

const int moveIncrement = 2;

void Player::Update() {
	LJS js;
	getJoystickXY(js, true);

	KeyboardInput ki;
	GetKeyboardInput(ki);

	if (js.x == HorizontalValue::Left || ki.x == KBDirectionX::LEFT) {
		this->destRect.x -= moveIncrement;
		this->currentFlip = SDL_FLIP_HORIZONTAL;
	} else if (js.x == HorizontalValue::Right || ki.x == KBDirectionX::RIGHT) {
		this->destRect.x += moveIncrement;
		this->currentFlip = SDL_FLIP_NONE;
	}

	if (js.y == VerticalValue::Up || ki.y == KBDirectionY::UP) {
		this->destRect.y -= moveIncrement;
	} else if (js.y == VerticalValue::Down || ki.y == KBDirectionY::DOWN) {
		this->destRect.y += moveIncrement;
	}
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

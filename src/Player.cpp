#include "Player.hpp"
#include "Controller.hpp"
#include "Keyboard.hpp"

const int moveIncrement = 2;

void Player::Update() {
	LJS js;
	getJoystickXY(js, true);

	KeyboardInput ki;
	GetKeyboardInput(&ki);

	if (js.x == HorizontalValue::Left || ki.x == KBDirectionX::LEFT) {
		this->destRect.x -= moveIncrement;
	} else if (js.x == HorizontalValue::Right || ki.x == KBDirectionX::RIGHT) {
		this->destRect.x += moveIncrement;
	}

	if (js.y == VerticalValue::Up || ki.y == KBDirectionY::UP) {
		this->destRect.y -= moveIncrement;
	} else if (js.y == VerticalValue::Down || ki.y == KBDirectionY::DOWN) {
		this->destRect.y += moveIncrement;
	}
}
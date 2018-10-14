#include "Player.hpp"
#include "Controller.hpp"
LJS movementJoystick;
void Player::Update() {
	if (Controller::IsControllerEnabled()) {
		getJoystickXY(movementJoystick, true);
		int increment = 2;
		if (!(int)movementJoystick.x) {
			this->destRect.x -= increment;
		} else if (movementJoystick.x == HorizontalValue::Right) {
			this->destRect.x += increment;
		}
		if (!(int)movementJoystick.y) {
			this->destRect.y -= increment;
		} else if (movementJoystick.y == VerticalValue::Down) {
			this->destRect.y += increment;
		}
	}
}
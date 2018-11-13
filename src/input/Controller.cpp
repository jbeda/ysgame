#include "Controller.hpp"
#include "../Game.hpp"
bool isEnabled;

const int SENSITIVITY = 10000;

void Controller::GetJoystickXY(JS & js, bool isLeft)
{
	if (!Controller::IsControllerEnabled()) {
		js.x = HorizontalValue::None;
		js.y = VerticalValue::None;
	}

	if (isLeft) {
		short x = this->GetState().Gamepad.sThumbLX;
		if (x < -SENSITIVITY) {
			js.x = HorizontalValue::Left;
		} else if (x > SENSITIVITY) {
			js.x = HorizontalValue::Right;
		} else {
			js.x = HorizontalValue::None;
		}
		short y = this->GetState().Gamepad.sThumbLY;
		if (y < -SENSITIVITY) {
			js.y = VerticalValue::Down;
		} else if (y > SENSITIVITY) {
			js.y = VerticalValue::Up;
		} else {
			js.y = VerticalValue::None;
		}
	} else {
		short x = this->GetState().Gamepad.sThumbRX;
		if (x < -SENSITIVITY) {
			js.x = HorizontalValue::Left;
		} else if (x > SENSITIVITY) {
			js.x = HorizontalValue::Right;
		} else {
			js.x = HorizontalValue::None;
		}
		short y = this->GetState().Gamepad.sThumbRY;
		if (y < -SENSITIVITY) {
			js.y = VerticalValue::Down;
		} else if (y > SENSITIVITY) {
			js.y = VerticalValue::Up;
		} else {
			js.y = VerticalValue::None;
		}
	}
}

bool Controller::IsControllerEnabled() {
	return isEnabled;
}
void Controller::SetControllerEnabled(bool enabled) {
	isEnabled = enabled;
}

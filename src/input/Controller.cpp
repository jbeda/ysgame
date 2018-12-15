#include "Controller.hpp"
#include "../Game.hpp"
bool isEnabled;

int sensitivity = 10000;

void Controller::GetJoystickXY(JS & js, bool isLeft)
{
	if (!Controller::IsControllerEnabled()) {
		js.x = HorizontalValue::None;
		js.y = VerticalValue::None;
	}

	if (isLeft) {
		short x = this->GetState().Gamepad.sThumbLX;
		if (x < -sensitivity) {
			js.x = HorizontalValue::Left;
		} else if (x > sensitivity) {
			js.x = HorizontalValue::Right;
		} else {
			js.x = HorizontalValue::None;
		}
		short y = this->GetState().Gamepad.sThumbLY;
		if (y < -sensitivity) {
			js.y = VerticalValue::Down;
		} else if (y > sensitivity) {
			js.y = VerticalValue::Up;
		} else {
			js.y = VerticalValue::None;
		}
	} else {
		short x = this->GetState().Gamepad.sThumbRX;
		if (x < -sensitivity) {
			js.x = HorizontalValue::Left;
		} else if (x > sensitivity) {
			js.x = HorizontalValue::Right;
		} else {
			js.x = HorizontalValue::None;
		}
		short y = this->GetState().Gamepad.sThumbRY;
		if (y < -sensitivity) {
			js.y = VerticalValue::Down;
		} else if (y > sensitivity) {
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

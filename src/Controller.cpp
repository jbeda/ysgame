#include "Controller.hpp"
#include "Game.hpp"
bool isEnabled;
bool Controller::IsControllerEnabled() {
	return isEnabled;
}
void Controller::SetControllerEnabled(bool enabled) {
	isEnabled = enabled;
}
#define plrC Game::getPlrController()
ControllerButton getControllerButtonState() {
	if (!Controller::IsControllerEnabled()) {
		return (ControllerButton)NULL;
	}

	if (plrC->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A) {
		return AButton;
	}
	if (plrC->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_B) {
		return BButton;
	}
	if (plrC->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X) {
		return XButton;
	}
	if (plrC->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_Y) {
		return YButton;
	}
	if (plrC->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) {
		return DPadDown;
	}
	if (plrC->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) {
		return DPadLeft;
	}
	if (plrC->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) {
		return DPadRight;
	}
	if (plrC->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) {
		return DPadUp;
	}
	return (ControllerButton)NULL;
}
#define SENSITIVITY 10000
void getJoystickXY(JS& joystickObj, bool isLeft) {
	if (!Controller::IsControllerEnabled()) {
		joystickObj.x = HorizontalValue::None;
		joystickObj.y = VerticalValue::None;
	}

	if (isLeft) {
		short x = plrC->GetState().Gamepad.sThumbLX;
		if (x < -SENSITIVITY) {
			joystickObj.x = HorizontalValue::Left;
		}
		else if (x > SENSITIVITY) {
			joystickObj.x = HorizontalValue::Right;
		}
		else {
			joystickObj.x = HorizontalValue::None;
		}
		short y = plrC->GetState().Gamepad.sThumbLY;
		if (y < -SENSITIVITY) {
			joystickObj.y = VerticalValue::Down;
		}
		else if (y > SENSITIVITY) {
			joystickObj.y = VerticalValue::Up;
		}
		else {
			joystickObj.y = VerticalValue::None;
		}
	} else {
		short x = plrC->GetState().Gamepad.sThumbRX;
		if (x < -SENSITIVITY) {
			joystickObj.x = HorizontalValue::Left;
		}
		else if (x > SENSITIVITY) {
			joystickObj.x = HorizontalValue::Right;
		}
		else {
			joystickObj.x = HorizontalValue::None;
		}
		short y = plrC->GetState().Gamepad.sThumbRY;
		if (y < -SENSITIVITY) {
			joystickObj.y = VerticalValue::Down;
		}
		else if (y > SENSITIVITY) {
			joystickObj.y = VerticalValue::Up;
		}
		else {
			joystickObj.y = VerticalValue::None;
		}
	}
}
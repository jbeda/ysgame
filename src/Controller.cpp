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
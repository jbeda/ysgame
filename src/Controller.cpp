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
	return (ControllerButton)NULL;
}
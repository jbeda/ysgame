#include "XBOXController.hpp"

XBOXController::XBOXController(int playerNum) {
	this->playerNum = playerNum - 1;
}

bool XBOXController::IsConnected() {
	ZeroMemory(&this->state, sizeof(XINPUT_STATE));
	DWORD r = XInputGetState(this->playerNum, &this->state);
	return (r == ERROR_SUCCESS);
}

XINPUT_STATE XBOXController::GetState() {
	ZeroMemory(&this->state, sizeof(XINPUT_STATE));
	XInputGetState(this->playerNum, &this->state);
	return this->state;
}

void XBOXController::Vibrate(double l, double r) {
	double rl = l;
	double rr = r;
	rl *= 65535;
	rr *= 65535;
	XINPUT_VIBRATION v;
	v.wLeftMotorSpeed = (int)rl;
	v.wRightMotorSpeed = (int)rr;
}
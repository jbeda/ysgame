#pragma once
#include "Controller.hpp"
class XBOXController : public Controller {
public:
	XBOXController(int playerNum);
	void Vibrate(double l, double r);
	bool IsConnected();
	XINPUT_STATE GetState();
};
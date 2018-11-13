#pragma once

#include <Windows.h>
#include <Xinput.h>
#pragma comment(lib, "XInput.lib")

enum  ControllerButton {
	AButton = 1,
	BButton = 2,
	XButton = 3,
	YButton = 4,
	DPadUp = 5,
	DPadDown = 6,
	DPadRight = 7,
	DPadLeft = 8
};

enum class HorizontalValue {
	Left,
	Right,
	None
};

enum class VerticalValue {
	Up,
	Down,
	None
};

struct JS {
	HorizontalValue x;
	VerticalValue y;
};

typedef JS LJS;
typedef JS RJS;

class Controller {
public:
	virtual bool IsConnected() = 0;
	virtual XINPUT_STATE GetState() = 0;
	virtual void Vibrate(double l, double r) = 0;
	virtual void GetJoystickXY(JS& js, bool isLeft);
	static bool IsControllerEnabled();
	static void SetControllerEnabled(bool enabled);
protected:
	XINPUT_STATE state;
	int playerNum;
};
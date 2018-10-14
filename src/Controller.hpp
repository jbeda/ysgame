#pragma once
#include <Windows.h>
#include <Xinput.h>
#pragma comment(lib, "XInput.lib")
enum class ControllerButton {
	AButton = 1,
	BButton = 2,
	XButton = 3,
	YButton = 4,
	DPadUp = 5,
	DPadDown = 6,
	DPadRight = 7,
	DPadLeft = 8
};

#define AButton ControllerButton::AButton
#define BButton ControllerButton::BButton
#define XButton ControllerButton::XButton
#define YButton ControllerButton::YButton
#define DPadUp ControllerButton::DPadUp
#define DPadDown ControllerButton::DPadDown
#define DPadRight ControllerButton::DPadRight
#define DPadLeft ControllerButton::DPadLeft

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

void getJoystickXY(JS&, bool);

ControllerButton getControllerButtonState();

class Controller {
public:
	virtual bool IsConnected() = 0;
	virtual XINPUT_STATE GetState() = 0;
	virtual void Vibrate(double l, double r) = 0;
	static bool IsControllerEnabled();
	static void SetControllerEnabled(bool enabled);
protected:
	XINPUT_STATE state;
	int playerNum;
};
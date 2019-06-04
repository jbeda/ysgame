#include "InputManager.hpp"
#include "XBOXController.hpp"
#include "Keyboard.hpp"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
	delete plrController;
}

void InputManager::init()
{
	plrController = new XBOXController(1);
}

void InputManager::update()
{
	Controller::SetControllerEnabled(this->plrController->IsConnected());
}

Move InputManager::GetMove()
{
	Move ret;

	LJS js;
	plrController->GetJoystickXY(js, true);

	KeyboardInput ki;
	GetKeyboardInput(ki);

	ret.x = XMove::XNone;
	if (js.x == HorizontalValue::Left || ki.x == KBDirectionX::LEFT) {
		ret.x = XMove::XLeft;
	}

	if (js.x == HorizontalValue::Right || ki.x == KBDirectionX::RIGHT) {
		if (ret.x != XMove::XNone) {
			// If both left and right are pressed, no move
			ret.x = XMove::XNone;
		} else {
			ret.x = XMove::XRight;
		}
	}

	ret.y = YMove::YNone;
	if (js.y == VerticalValue::Up || ki.y == KBDirectionY::UP) {
		ret.y = YMove::YUp;
	}

	if (js.y == VerticalValue::Down || ki.y == KBDirectionY::DOWN) {
		if (ret.y != YMove::YNone) {
			// If both up and down are pressed, no move
			ret.y = YMove::YNone;
		} else {
			ret.y = YMove::YDown;
		}
	}

	return ret;
}

bool InputManager::GetAttack()
{
	KeyboardInput ki;
	GetKeyboardInput(ki);

	bool btn = this->plrController->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_X;

	return btn || ki.attack;
}

bool InputManager::GetPickup()
{
	KeyboardInput kb;
	GetKeyboardInput(kb);

	bool btn = this->plrController->GetState().Gamepad.wButtons & XINPUT_GAMEPAD_A;

	return btn || kb.pickup;
}

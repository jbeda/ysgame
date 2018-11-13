#pragma once
#include "Controller.hpp"

enum class XMove {
	XNone,
	XLeft,
	XRight,
};

enum class YMove {
	YNone,
	YUp,
	YDown,
};

struct Move {
	XMove x;
	YMove y;
};

class InputManager
{
public:
	InputManager();
	~InputManager();

	void init();
	void update();

	Move GetMove();
	bool GetAttack();
	bool GetPickup();

private:
	Controller* plrController = NULL;
};


#pragma once

enum class KBDirectionX {
	NONE,
	LEFT,
	RIGHT
};

enum class KBDirectionY {
	NONE,
	UP,
	DOWN
};

struct KeyboardInput {
	KBDirectionX x;
	KBDirectionY y;
	bool attack;
};

void GetKeyboardInput(KeyboardInput* ki);

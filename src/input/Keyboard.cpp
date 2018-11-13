#include "Keyboard.hpp"
#include <SDL.h>
#define KBS(sc) SDL_GetKeyboardState(NULL)[sc]
#define KeyBoardButtonPressed(scancode) static_cast<bool>(KBS(scancode))
void GetKeyboardInput(KeyboardInput& ki) {
	// Handle left/right
	ki.x = KBDirectionX::NONE;
	if (KBS(SDL_SCANCODE_A)) {
		ki.x = KBDirectionX::LEFT;
	}
	if (KBS(SDL_SCANCODE_D)) {
		// If both keys are pressed, act like none are pressed
		if (ki.x != KBDirectionX::NONE) {
			ki.x = KBDirectionX::NONE;
		}
		else {
			ki.x = KBDirectionX::RIGHT;
		}
	}

	// Handle up/down
	ki.y = KBDirectionY::NONE;
	if (KBS(SDL_SCANCODE_W)) {
		ki.y = KBDirectionY::UP;
	}
	if (KBS(SDL_SCANCODE_S)) {
		// If both keys are pressed, act like none are pressed
		if (ki.y != KBDirectionY::NONE) {
			ki.y = KBDirectionY::NONE;
		}
		else {
			ki.y = KBDirectionY::DOWN;
		}
	}

	// Handle keyboard actions
	ki.attack = KeyBoardButtonPressed(SDL_SCANCODE_R);
	ki.pickup = KeyBoardButtonPressed(SDL_SCANCODE_C);
}

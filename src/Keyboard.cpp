#include "Keyboard.hpp"
#include <SDL.h>

void GetKeyboardInput(KeyboardInput* ki) {
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	// Handle left/right
	ki->x = KBDirectionX::NONE;
	if (state[SDL_SCANCODE_A]) {
		ki->x = KBDirectionX::LEFT;
	}
	if (state[SDL_SCANCODE_D]) {
		// If both keys are pressed, act like none are pressed
		if (ki->x != KBDirectionX::NONE) {
			ki->x = KBDirectionX::NONE;
		}
		else {
			ki->x = KBDirectionX::RIGHT;
		}
	}

	// Handle up/down
	ki->y = KBDirectionY::NONE;
	if (state[SDL_SCANCODE_W]) {
		ki->y = KBDirectionY::UP;
	}
	if (state[SDL_SCANCODE_S]) {
		// If both keys are pressed, act like none are pressed
		if (ki->y != KBDirectionY::NONE) {
			ki->y = KBDirectionY::NONE;
		}
		else {
			ki->y = KBDirectionY::DOWN;
		}
	}

	// Handle attack
	ki->attack = static_cast<bool>(state[SDL_SCANCODE_SPACE]);
}

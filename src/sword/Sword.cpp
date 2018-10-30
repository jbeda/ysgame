#include "Sword.hpp"
#include "../Player.hpp"
#include "../Game.hpp"
#include "../Controller.hpp"
#include "../Keyboard.hpp"
#include "../util/debugging/notif.h"

void Sword::Update() {
	if (rotation == 135 || rotation == -135) {
		DebugMessage("135 deg now resetting");
		this->ResetSwing();
	}
	if (this->swinging) {
		if (gGame->getPlr()->getRenderFlip() == SDL_FLIP_NONE) {
			this->Rotate(3);
			this->destRect.x += 1;
		}
		else {
			this->Rotate(-3);
			this->destRect.x -= 1;
		}
		this->destRect.y += 0.5;
	}
	else {
		this->destRect.y = gGame->getPlr()->getLocation()->y + 5;
		if (gGame->getPlr()->getRenderFlip() == SDL_FLIP_NONE)
			this->destRect.x = gGame->getPlr()->getLocation()->x + 20;
		else
			this->destRect.x = gGame->getPlr()->getLocation()->x - 7;
	}

	switch (getControllerButtonState()) {
	case XButton:
		if (!gGame->getPlr()->getCurrentEffect())
			this->Swing();
		else
			if (gGame->getPlr()->getCurrentEffect()->Use())
				gGame->getPlr()->ClearEffect();
		break;
	}

	KeyboardInput ki;
	GetKeyboardInput(ki);
	if (ki.attack) {
		if (!gGame->getPlr()->getCurrentEffect())
			this->Swing();
		else
			if (gGame->getPlr()->getCurrentEffect()->Use())
				gGame->getPlr()->ClearEffect();
	}
}
void Sword::ResetSwing() {
	this->swinging = false;
	this->rotation = 0;
}
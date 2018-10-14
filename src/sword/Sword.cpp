#include "Sword.hpp"
#include "../Player.hpp"
#include "../Game.hpp"
#include "../Controller.hpp"
#include "../util/debugging/notif.h"
void Sword::Update() {
	if (rotation == 135) {
		DebugMessage("135 deg now resetting");
		this->ResetSwing();
	}
	if (this->swinging) {
		this->Rotate(3);
		this->destRect.y += 0.5;
		this->destRect.x += 1;
	}
	else {
		this->destRect.y = Game::getPlr()->getLocation()->y + 5;
		this->destRect.x = Game::getPlr()->getLocation()->x + 20;
	}
	if (Controller::IsControllerEnabled()) {
		switch (getControllerButtonState()) {
		case XButton:
			this->Swing();
			break;
		}
	}
}
void Sword::ResetSwing() {
	this->swinging = false;
	this->rotation = 0;
}
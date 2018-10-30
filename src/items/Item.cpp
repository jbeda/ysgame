#include "Item.hpp"
#include "../Game.hpp"
#include "../Player.hpp"
#include "../Controller.hpp"
#include "../util/debugging/notif.h"
#include "../Keyboard.hpp"
void Item::Update() {
	KeyboardInput kb;
	GetKeyboardInput(kb);
	if ((this->Collided(Plane::X, *gGame->getPlr()) & this->Collided(Plane::Y, *gGame->getPlr())) & (getControllerButtonState() == AButton || kb.pickup)) {
		// Hand off ownership of effect to player
		gGame->getPlr()->AddEffect(this->effect);
		this->effect = NULL;
		this->dead = true;
		DebugMessage("picked up item");
	}
}
std::string EffectToStr(PlayerEffect effect) {
	switch (effect) {
	case PlayerEffect::Grenade:
		return "Grenade";
	case PlayerEffect::HoningKnife:
		return "Honing Throws";
	case PlayerEffect::RapidThrow:
		return "Rapid Throw";
	case PlayerEffect::Wiper:
		return "Wiper";
	}
}
#include "Item.hpp"
#include "../Game.hpp"
#include "../Player.hpp"
#include "../Controller.hpp"
#include "../util/debugging/notif.h"
#include "../Keyboard.hpp"
void Item::Update() {
	KeyboardInput kb;
	GetKeyboardInput(kb);
	if ((this->Collided(Plane::X, *Game::getPlr()) & this->Collided(Plane::Y, *Game::getPlr())) & (getControllerButtonState() == AButton || kb.pickup)) {
		Game::getPlr()->AddEffect(this->effect);
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
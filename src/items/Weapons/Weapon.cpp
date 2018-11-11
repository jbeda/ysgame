#include "Weapon.hpp"
#include "../../util/debugging/notif.h"
Weapon::Weapon(PlayerEffect effect) : GameObject(NULL, 0, 0) {
	this->effect = effect;
	switch (this->effect) {
	case PlayerEffect::Grenade:
		this->maxuses = 3;
		break;
	case PlayerEffect::HoningKnife:
		this->maxuses = 5;
		break;
	case PlayerEffect::RapidThrow:
		this->maxuses = 20;
		break;
	case PlayerEffect::Wiper:
		this->maxuses = 1;
		break;
	}
}
bool Weapon::Use() {
	this->uses++;
	DebugMessage("used other weapon");
	return (this->uses >= this->maxuses);
}
std::string EffectToStr(PlayerEffect effect) {
	switch (effect) {
	case PlayerEffect::Grenade:
		return "Grenade";
	case PlayerEffect::HoningKnife:
		return "Honing Knife";
	case PlayerEffect::RapidThrow:
		return "Rapid Throw";
	case PlayerEffect::Wiper:
		return "Wiper";
	}
}
#include "Weapon.hpp"
#include "../../Game.hpp"
#include "../../Player.hpp"
#include "../../util/debugging/notif.h"
#define plr gGame->getPlr()
Weapon::Weapon(PlayerEffect effect) : GameObject(NULL, 0, 0, EItem) {
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
	DebugMessage(("used other weapon: " + EffectToStr(this->getEnumeration())).c_str());
	switch (this->getEnumeration()) {
	case PlayerEffect::Grenade:
		for (auto& o : gGame->getObjectList())
			if (o->getObjType() == EEnemy) {
				if (plr->Radius(*o, 1))
					o->hurt(3);
				else if (plr->Radius(*o, 2))
					o->hurt(2);
				else if (plr->Radius(*o, 3))
					o->hurt(1);
			}
		break;
	case PlayerEffect::HoningKnife:
		OoO();
		break;
	case PlayerEffect::RapidThrow:
		OoO();
		break;
	case PlayerEffect::Wiper:
		for (auto& o : gGame->getObjectList())
			if (o->getObjType() == EEnemy)
				o->dead = true;
		break;
	}
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
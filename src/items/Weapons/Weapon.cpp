#include "Weapon.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "util/debugging/notif.h"
#include "sword/RapidKnife.hpp"
#include "sword/HomingKnife.hpp"
#include "Enemy.hpp"

#define plr gGame->getPlr()
template <typename KnifeType> void ThrowKnife() {
	Sword* s = new KnifeType();
	gGame->addObject(s);
	s->Swing();
}
Weapon::Weapon(PlayerEffect effect) : SimpleGameObject(NULL, 0, 0, EItem) {
	this->effect = effect;
	switch (this->effect) {
	case PlayerEffect::Grenade:
		this->maxuses = 3;
		break;
	case PlayerEffect::HomingKnife:
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
				auto enemy = dynamic_cast<Enemy*>(o.get());
				if (plr->Radius(*enemy, 1))
					enemy->hurt(3);
				else if (plr->Radius(*enemy, 2))
					enemy->hurt(2);
				else if (plr->Radius(*enemy, 3))
					enemy->hurt(1);
			}
		break;
	case PlayerEffect::HomingKnife:
		ThrowKnife<_HomingKnife>();
		break;
	case PlayerEffect::RapidThrow:
		ThrowKnife<RapidKnife>();
		break;
	case PlayerEffect::Wiper:
		for (auto& o : gGame->getObjectList()) {
			if (o->getObjType() == EEnemy) {
				dynamic_cast<Enemy*>(o.get())->Kill();
			}
		}
		break;
	}
	return (this->uses >= this->maxuses);
}
std::string EffectToStr(PlayerEffect effect) {
	switch (effect) {
	case PlayerEffect::Grenade:
		return "Grenade";
	case PlayerEffect::HomingKnife:
		return "Honing Knife";
	case PlayerEffect::RapidThrow:
		return "Rapid Throw";
	case PlayerEffect::Wiper:
		return "Wiper";
	}
	return "UNKNOWN";
}
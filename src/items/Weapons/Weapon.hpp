#pragma once
#include "../../SimpleGameObject.hpp"
#include "../../util/include.h"
enum class PlayerEffect {
	Wiper,
	Grenade,
	HomingKnife,
	RapidThrow,
	None
};
class Weapon : SimpleGameObject
{
public:
	Weapon(PlayerEffect effect);
	PlayerEffect getEnumeration() { return this->effect; }
	bool Use();
	int UsesLeft() {
		return this->maxuses - this->uses;
	}
private:
	PlayerEffect effect = PlayerEffect::None;
	int uses = 0;
	int maxuses = 0;
};
#define NA Weapon(PlayerEffect::None)
std::string EffectToStr(PlayerEffect effect);
#pragma once
#include "../../GameObject.hpp"
#include "../../util/include.h"
enum class PlayerEffect {
	Wiper,
	Grenade,
	HoningKnife,
	RapidThrow,
	None
};
class Weapon : GameObject
{
public:
	Weapon(PlayerEffect effect);
	PlayerEffect getEnumeration() { return this->effect; }
	bool Use();
private:
	PlayerEffect effect;
	int uses = 0;
	int maxuses;
};
#define NA Weapon(PlayerEffect::None)
std::string EffectToStr(PlayerEffect effect);
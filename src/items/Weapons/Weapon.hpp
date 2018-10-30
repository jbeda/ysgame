#pragma once
enum class PlayerEffect {
	Wiper,
	Grenade,
	HoningKnife,
	RapidThrow,
	None
};
class Weapon
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
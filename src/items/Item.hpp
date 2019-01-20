#pragma once
#include "../GameObject.hpp"
#include "../util/include.h"
#include "weapons/Weapon.hpp"

class Item : public GameObject {
public:
	Item(const char* itemImage, int x, int y, PlayerEffect effect) : GameObject(itemImage, x, y, EItem) { 
		this->effect = new Weapon(effect); 
	}

	~Item() {
		delete this->effect;
	}
	void Update();
protected:
	Weapon* effect = NULL;
	std::string name, desc;
	int uses;
};
#define Grenade(x, y) Item("Grenade.png", (x * 32) + 1, (y * 32) + 1, PlayerEffect::Grenade)
#define Wiper(x, y) Item("Wiper.png", (x * 32) + 1, (y * 32) + 1, PlayerEffect::Wiper)
#define HomingKnife(x, y) Item("Honing.png", (x * 32) + 1, (y * 32) + 1, PlayerEffect::HomingKnife)
#define RapidThrow(x, y) Item("RapidThrow.png", (x * 32) + 1, (y * 32) + 1, PlayerEffect::RapidThrow)
#pragma once
#include "../GameObject.hpp"
#include "../util/include.h"
enum class PlayerEffect {
	Wiper,
	Grenade,
	HoningKnife,
	RapidThrow
};
// For debugging
std::string EffectToStr(PlayerEffect effect);
class Item : public GameObject {
public:
	Item(const char* itemImage, int x, int y, PlayerEffect effect) : GameObject(itemImage, x, y) { this->effect = effect; }
	void Update();
protected:
	PlayerEffect effect;
	std::string name, desc;
	int uses;
};
#define Grenade(x, y) Item("Grenade.png", (x * 32) + 1, (y * 32) + 1, PlayerEffect::Grenade)
#define Wiper(x, y) Item("Wiper.png", (x * 32) + 1, (y * 32) + 1, PlayerEffect::Wiper)
#define HoningKnife(x, y) Item("Honing.png", (x * 32) + 1, (y * 32) + 1, PlayerEffect::HoningKnife)
#define RapidThrow(x, y) Item("RapidThrow.png", (x * 32) + 1, (y * 32) + 1, PlayerEffect::RapidThrow)
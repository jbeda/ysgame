#pragma once
#include "../Game.hpp"
#include "../GameObject.hpp"
#include "../util/include.h"
#include "weapons/Weapon.hpp"
#include "../ui/Form.hpp"
#include "../Map.hpp"
#include <cstdlib>

class Item : public GameObject {
public:
	Item(std::string name, const char* itemImage, int x, int y, PlayerEffect effect) : GameObject(itemImage, x, y, EItem) { 
		this->effect = new Weapon(effect);
		YColor fc = { 255,255,255,255 };
		this->form = new UIForm(x, y - TILE2PIX(2.5), TILE2PIX(5), TILE2PIX(2.5), fc);
		YColor tc = { 0,0,0,255 };
		Widget* w1 = new Widget(this->form, 10, 10, 64, 48, WidgetType::WLabel, name, Widget::Arial, tc);
		char uses[100];
		itoa(this->effect->UsesLeft(), uses, 10);
		Widget* w2 = new Widget(this->form, 10, 42, 16, 8, WidgetType::WLabel, (std::string("Uses: ") + std::string(uses)), Widget::Arial, tc);
		gGame->addObject(w1);
		gGame->addObject(w2);
		gGame->addObject(this->form);
		this->form->Activate();
	}

	~Item() {
		delete this->effect;
	}
	void Update();
protected:
	Weapon* effect = NULL;
	std::string name, desc;
	int uses = 0;
	UIForm* form = NULL;
};
#define Grenade(x, y) Item("Grenade", "Grenade.png", TILE2PIX(x) + 1, TILE2PIX(y) + 1, PlayerEffect::Grenade)
#define Wiper(x, y) Item("Wiper", "Wiper.png", TILE2PIX(x) + 1, TILE2PIX(y) + 1, PlayerEffect::Wiper)
#define HomingKnife(x, y) Item("Homing Knife", "Honing.png", TILE2PIX(x) + 1, TILE2PIX(y) + 1, PlayerEffect::HomingKnife)
#define RapidThrow(x, y) Item("Rapid Throw", "RapidThrow.png", TILE2PIX(x) + 1, TILE2PIX(y) + 1, PlayerEffect::RapidThrow)
#pragma once
#include "../Game.hpp"
#include "../SimpleGameObject.hpp"
#include "../util/include.h"
#include "weapons/Weapon.hpp"
#include "../ui/Form.hpp"
#include "../Map.hpp"
#include <cstdlib>

class Item : public SimpleGameObject {
public:
	Item(std::string name, const char* itemImage, int x, int y, PlayerEffect effect) : SimpleGameObject(itemImage, x, y, EItem) { 
		this->effect = new Weapon(effect);
		YColor fc = { 255,255,255,255 };
		this->form = new UIForm(x, y - TILE2PIX(2.5), TILE2PIX(1) + 24 * (std::strlen(name.c_str()) - 1), TILE2PIX(2.5), fc);
		YColor tc = { 0,0,0,255 };
		Widget* w1 = new Widget(this->form, 10, 10, 48, WidgetType::WLabel, name, Widget::Consolas, tc);
		char uses[100];
		itoa(this->effect->UsesLeft(), uses, 10);
		Widget* w2 = new Widget(this->form, 10, 50, 16, WidgetType::WLabel, (std::string("Uses: ") + std::string(uses)), Widget::Consolas, tc);
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
#define GrenadeInit(x, y) Item("Grenade", "Grenade.png", TILE2PIX(x) + 1, TILE2PIX(y) + 1, PlayerEffect::Grenade)
#define WiperInit(x, y) Item("Wiper", "Wiper.png", TILE2PIX(x) + 1, TILE2PIX(y) + 1, PlayerEffect::Wiper)
#define HomingKnifeInit(x, y) Item("Homing Knife", "Homing.png", TILE2PIX(x) + 1, TILE2PIX(y) + 1, PlayerEffect::HomingKnife)
#define RapidThrowInit(x, y) Item("Rapid Throw", "RapidThrow.png", TILE2PIX(x) + 1, TILE2PIX(y) + 1, PlayerEffect::RapidThrow)
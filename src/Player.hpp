#pragma once
#include "SimpleGameObject.hpp"
#include "sword/Sword.hpp"
#include "items/Item.hpp"
class Player :
	public SimpleGameObject
{
public:
	Player() : SimpleGameObject("Player.png", 0, 0, EPlayer) { this->sw = new Sword(); }

	void Update();
	void Render();
	Sword* sw;
	virtual ~Player() {
		delete sw;
		delete this->effect;
	}
	void AddEffect(Weapon*);
	Weapon* getCurrentEffect() { return this->effect; }
	void ClearEffect();

private:
	Weapon* effect = NULL;
};
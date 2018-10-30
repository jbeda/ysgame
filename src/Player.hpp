#pragma once
#include "GameObject.hpp"
#include "sword/Sword.hpp"
#include "items/Item.hpp"
class Player :
	public GameObject
{
public:
	Player() : GameObject("Player.png", 0, 0) { this->sw = new Sword(); }

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
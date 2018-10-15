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
	Sword* sw;
	~Player() {
		delete sw;
	}
	void AddEffect(PlayerEffect);
};
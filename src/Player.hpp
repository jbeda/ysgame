#pragma once
#include "GameObject.hpp"
class Player :
	public GameObject
{
public:
	Player() : GameObject("Player.png", 0, 0) { }
	void Update();
};
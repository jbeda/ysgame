#pragma once
#include "../GameObject.hpp"

class Sword :
	public GameObject
{
public:
	Sword() : GameObject("Sword.png", 0, 0) { this->rotation = 0; }
	void Update();
	void Swing() { this->swinging = true; }
	void ResetSwing();
	bool IsSwinging() { return this->swinging; }
private:
	bool swinging = false;
};
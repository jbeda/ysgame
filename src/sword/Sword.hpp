#pragma once
#include "../SimpleGameObject.hpp"
#include "../items/Weapons/Weapon.hpp"
#include "../sound/Sound.hpp"
class Sword :
	public SimpleGameObject
{
public:
	Sword() : SimpleGameObject("Sword.png", 0, 0, EItem) { this->rotation = 0; }
	virtual void Update();
	void Swing() { this->swinging = true; SoundEffect::PlayOGG(SFX::ThrowKnife); }
	void ResetSwing();
	bool IsSwinging() { return this->swinging; }
protected:
	bool swinging = false;

	// This is true after an effect is applied until the attack button is lifted.
	bool effectApplied = false;
};
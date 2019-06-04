#pragma once
#include "GameObject.hpp"
#include "CompositeObject.h"
#include "Vector2D.hpp"

class ParticleSystem :
	public CompositeObject
{
	ParticleSystem(Vector2f pos);
	virtual void Update();
	virtual void Render();
	virtual bool IsDead();
};


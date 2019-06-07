#pragma once
#include "GameObject.hpp"
#include "CompositeObject.hpp"
#include "Vector2D.hpp"
#include <SDL.h>
class Particle : public CompositeChild {
public:
	Particle(SDL_Color color, int lifetime, int decay);
	virtual void Update();
	virtual void Render(Vector2f pos);
private:
	SDL_Color color;
	int lifetime, decay;
};
class ParticleSystem : public CompositeObject {
public:
	ParticleSystem(Vector2f pos, int lifetime, int decay);
	virtual void Update();
	virtual void Render() {}
protected:
	int lifetime, decay;
};
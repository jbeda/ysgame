#pragma once
#include "GameObject.hpp"
#include "CompositeObject.hpp"
#include "Vector2D.hpp"
#include <SDL.h>
class Particle : public GameObject {
public:
	Particle(SDL_Color color, int lifetime, int decay, Vector2f vel);
	virtual void Update();
	virtual void Render();
	virtual bool IsDead() { return lifetime <= 0; }
private:
	Vector2f pos;
	Vector2f vel;

	SDL_Color color;
	int maxLifetime, lifetime, decay;
};

// Ideas:
// Have the particle system burn out over time (N particles?) and mark itself dead
// Give the particle system it's own velocity/acceleration
// Acceleration for particles
// Different color particles
// Use an image with alpha for particles and color them

class ParticleSystem : public CompositeObject {
public:
	ParticleSystem(Vector2f pos, int lifetime, int decay);
	virtual void Update();
protected:
	int lifetime, decay;
};
#include "Game.hpp"
#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(Vector2f pos, int lifetime, int decay) : CompositeObject(pos), lifetime(lifetime), decay(decay) {
	this->type = EParticleSystem;
}

void ParticleSystem::Update() {
	auto vel = Vector2f::FromAngle(gGame->Random(0, 2.0 * PI), 1.0);
	this->AddObject(new Particle({255, 255, 255, 255}, this->lifetime, this->decay, vel));
	CompositeObject::Update();
}

Particle::Particle(SDL_Color color, int lifetime, int decay, Vector2f vel) 
	: GameObject(EParticleSystem), maxLifetime(lifetime), lifetime(lifetime), color(color), decay(decay), vel(vel) { }

void Particle::Update() {
	color.a = (static_cast<float>(lifetime) / maxLifetime) * 255;
	this->lifetime -= this->decay;

	this->pos = this->pos + this->vel;
}

void Particle::Render() {
	SDL_Rect p;

	p.x = pos.x;
	p.y = pos.y;
	p.w = 2;
	p.h = 2;

	gGame->renderer.SetDrawColor(&color);
	gGame->renderer.FillRect(&p);
}
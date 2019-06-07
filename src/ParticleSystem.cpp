#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(Vector2f pos, int lifetime, int decay) : CompositeObject(pos), lifetime(lifetime), decay(decay) {
	this->type = EParticleSystem;
}
void ParticleSystem::Update() {
	this->AddObject(new Particle({255, 255, 255, 255}, this->lifetime, this->decay));
}
Particle::Particle(SDL_Color color, int lifetime, int decay) : CompositeChild(EParticleSystem), lifetime(lifetime), color(color), decay(decay) { }
void Particle::Update() {
	this->color = { color.r, color.g, color.b, static_cast<Uint8>(this->lifetime) };
	this->lifetime -= this->decay;
}
void Particle::Render(Vector2f pos) {
	SDL_Rect p;
}
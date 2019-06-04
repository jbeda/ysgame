#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Vector2f pos) : CompositeObject(pos) {
	this->type = EParticleSystem;
}

void ParticleSystem::Update()
{
}

void ParticleSystem::Render()
{
}

bool ParticleSystem::IsDead()
{
	return false;
}

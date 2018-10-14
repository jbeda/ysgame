#include <stdio.h>
#include "GameObject.hpp"
#include "TextureManager.hpp"
#include "Game.hpp"
#include "util/numbers.h"

GameObject::GameObject(const char* imgPath, int x, int y, int maxhp) {
	this->id = latestId;
	latestId++;

	this->maxhp = maxhp;
	this->hp = this->maxhp;

	this->img = NULL;
	if (imgPath != NULL) {
		this->img = TextureManager::LoadTexture(imgPath);

		SDL_QueryTexture(this->img, NULL, NULL, &(this->srcRect.w), &(this->srcRect.h));
	}
	else {
		this->srcRect.w = 32;
		this->srcRect.h = 32;
	}

	this->srcRect.x = 0;
	this->srcRect.y = 0;

	this->destRect.x = x;
	this->destRect.y = y;
	this->destRect.w = this->srcRect.w * 2;
	this->destRect.h = this->srcRect.w * 2;
}

void GameObject::Render() {
	if (TextureManager::Draw(this->img, this->srcRect, this->destRect, this->rotation)) {
		printf("Error calling SDL_RenderCopy: %s\n", SDL_GetError());
	}
}

GameObject::~GameObject() {
	if (this->img) {
		SDL_DestroyTexture(this->img);
	}
}
#define COLLISION_RANGE 15
bool GameObject::Collided(Plane p, GameObject& obj) {
	switch (p) {
	case Plane::X:
		return IsInRange(this->destRect.x, obj.getLocation()->x, COLLISION_RANGE);
		break;
	case Plane::Y:
		return IsInRange(this->destRect.y, obj.getLocation()->y, COLLISION_RANGE);
		break;
	}
}
int GameObject::latestId = 0;
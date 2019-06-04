#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL.h>
#include "GameObject.hpp"
#include "Vector2D.hpp"
#include <string>
#include "util/debugging/notif.h"

enum class Plane {
	X,
	Y
};

class SimpleGameObject : public GameObject  {
public:
	SimpleGameObject(const char* texFile, int x, int y, EntityType type, int maxhp = 10);
	virtual ~SimpleGameObject();

	Vector2f getLocation() { return Vector2f(destRect.x, destRect.y); }

	SDL_Texture* getImage() { return this->img; }

	SDL_RendererFlip getRenderFlip() { return this->currentFlip; }

	virtual void Update() {}
	virtual void Render();
	virtual bool IsDead() { return dead; }

	void Rotate(double rotation) { this->rotation += rotation; }
	int getHP() { return this->hp; }
	void hurt(int dmg) {
		this->hp -= dmg;
		char buf[128];
		_itoa(this->id, buf, 10);
		DebugMessage(("i got hurt " + std::string(buf)).c_str());
	}

	bool Collided(Plane p, SimpleGameObject& obj);
	bool Radius(SimpleGameObject& obj, int radius);
	int getID() { return this->id; }
protected:
	SDL_Rect srcRect;
	SDL_Rect destRect;
	SDL_Texture* img;
	double rotation = 0;
	int hp;
	int maxhp;
	int id;
	static int latestId;
	SDL_RendererFlip currentFlip = SDL_FLIP_NONE;
	bool dead = false;
};
#endif
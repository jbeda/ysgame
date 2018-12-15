#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL.h>
enum class Plane {
	X,
	Y
};
enum EntityType {
	EPlayer,
	EEnemy,
	EMap,
	EItem,
	EUI
};
class GameObject {
public:
	GameObject(const char* texFile, int x, int y, EntityType type, int maxhp = 10);
	virtual ~GameObject();

	SDL_Rect* getLocation() { return &(this->destRect); }

	SDL_Texture* getImage() { return this->img; }

	SDL_RendererFlip getRenderFlip() { return this->currentFlip; }

	virtual void Update() { }
	virtual void Render();
	virtual void Rotate(double rotation) { this->rotation += rotation; }
	int getHP() { return this->hp; }
	void hurt(int dmg) { this->hp -= dmg; }
	bool dead = false;
	EntityType getObjType() { return this->type; }
	bool Collided(Plane p, GameObject& obj);
	bool Radius(GameObject& obj, int radius);
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
	EntityType type;
};
#endif
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL.h>
enum class Plane {
	X,
	Y
};
class GameObject {
public:
    GameObject(const char* texFile, int x, int y, int maxhp = 10);
    ~GameObject();

    SDL_Rect* getLocation() { return &(this->destRect); }

    SDL_Texture* getImage() { return this->img; }

    virtual void Update() { }
    virtual void Render();
	virtual void Rotate(double rotation) { this->rotation += rotation; }
	int getHP() { return this->hp; }
	bool dead = false;
protected:
	bool Collided(Plane, GameObject&);
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Texture* img;
	double rotation = 0;
	int hp;
	int maxhp;
	int id;
	static int latestId;
};
#endif
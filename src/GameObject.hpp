#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL.h>

class GameObject {
public:
    GameObject(const char* texFile, int x, int y);
    ~GameObject();

    SDL_Rect* getLocation() { return &(this->destRect); }

    SDL_Texture* getImage() { return this->img; }

    virtual void Update();
    virtual void Render();

protected:
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Texture* img;
};

#endif
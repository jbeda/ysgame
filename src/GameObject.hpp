#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL.h>

class GameObject {
public:
    GameObject(const char* texFile, int x, int y, SDL_Renderer* ren);
    ~GameObject();

    SDL_Rect* getLocation() { return &(this->destRect); }

    SDL_Texture* getImage() { return this->img; }

    void Update();
    void Render();

private:
    SDL_Rect srcRect;
    SDL_Rect destRect;
    SDL_Texture* img;
    SDL_Renderer* renderer;
};

#endif
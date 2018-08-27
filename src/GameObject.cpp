#include <stdio.h>
#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* imgPath, int x, int y, SDL_Renderer* ren) {
    this->renderer = ren;

    this->img = TextureManager::LoadTexture(imgPath, ren);

    SDL_QueryTexture(this->img, NULL, NULL, &(this->srcRect.w), &(this->srcRect.h));

    this->srcRect.x = 0;
    this->srcRect.y = 0;

    this->destRect.x = x;
    this->destRect.y = y;
    this->destRect.w = this->srcRect.w * 2;
    this->destRect.h = this->srcRect.w * 2;
}

void GameObject::Update() {
    this->destRect.x++;
}

void GameObject::Render() {
    if (SDL_RenderCopy(this->renderer, this->img, &(this->srcRect), &(this->destRect))) {
        printf("Error calling SDL_RenderCopy: %s\n", SDL_GetError());
    }
}

GameObject::~GameObject() {

    SDL_DestroyTexture(this->img);
}

#include "Character.hpp"
#include <SDL_image.h>
#include <stdio.h>
#include "TextureManager.hpp"

Character::Character(const char* imgPath, int x, int y, int w, int h, SDL_Renderer* ren) {
    this->curLoc = new SDL_Rect();
    this->setX(x);
    this->setY(y);
    this->setWidth(w);
    this->setHeight(h);
    this->img = TextureManager::LoadTexture(imgPath, ren);
}
Character::~Character() {
    delete this->curLoc;
    SDL_DestroyTexture(this->img);
}
void Character::setX(int x) {
    this->curLoc->x = this->x = x;
}
void Character::setY(int y) {
    this->curLoc->y = this->y = y;
}
void Character::setWidth(int w) {
    this->curLoc->w = this->w = w;
}
void Character::setHeight(int h) {
    this->curLoc->h = this->h = h;
}
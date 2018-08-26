#include "Character.hpp"
#include <SDL_image.h>
#include <stdio.h>

Character::Character(const char* imgPath, int x, int y, int w, int h, SDL_Renderer* ren) {
    this->curLoc = new SDL_Rect();
    this->setX(x);
    this->setY(y);
    this->setWidth(w);
    this->setHeight(h);

    SDL_Surface* tmpSurface = IMG_Load(imgPath);
	if (tmpSurface == NULL) {
		printf("Error loading image %s: %s\n", imgPath, IMG_GetError());
	}
    this->img = SDL_CreateTextureFromSurface(ren, tmpSurface);
	if (this->img == NULL) {
		printf("Error creating texture %s: %s\n", imgPath, SDL_GetError());
	}
    SDL_FreeSurface(tmpSurface);
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
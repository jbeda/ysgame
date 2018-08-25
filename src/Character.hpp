#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SDL.h>

class Character {
public:
    Character(const char*, int, int, int, int, SDL_Renderer*);
    void setWidth(int);
    int getWidth() { return this->w; }
    void setHeight(int);
    int getHeight() { return this->h; }
    void setX(int);
    int getX() { return this->x; }
    void setY(int);
    int getY() { return this->y; }
    SDL_Rect* getLocation() { return this->curLoc; }
    ~Character();
    SDL_Texture* getImage() { return this->img; }
private:
    int w;
    int h;
    int x;
    int y;
    SDL_Rect* curLoc;
    SDL_Texture* img;
};

#endif
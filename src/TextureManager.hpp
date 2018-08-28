#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include <SDL.h>

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char*);
    static void Draw(SDL_Texture*, SDL_Rect, SDL_Rect);
};

#endif
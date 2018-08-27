#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP
#include <SDL.h>

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char*, SDL_Renderer*);
};

#endif
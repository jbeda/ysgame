#include "TextureManager.hpp"
#include <stdio.h>
#include <SDL_image.h>

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* ren) {
    SDL_Surface* tmpSurface = IMG_Load(filename);
    if (tmpSurface == NULL) {
        printf("Error loading image %s: %s\n", filename, IMG_GetError());
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, tmpSurface);
    if (texture == NULL) {
        printf("Error creating texture %s: %s\n", filename, SDL_GetError());
    }
    SDL_FreeSurface(tmpSurface);
    return texture;
}
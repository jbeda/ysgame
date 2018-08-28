#include "TextureManager.hpp"
#include <stdio.h>
#include <SDL_image.h>
#include <string>

SDL_Texture* TextureManager::LoadTexture(const char* filename, SDL_Renderer* ren) {
    std::string newFilenameStdStr = "assets\\" + (std::string)filename;
    const char* newFilename = newFilenameStdStr.c_str();
    SDL_Surface* tmpSurface = IMG_Load(newFilename);
    if (tmpSurface == NULL) {
        printf("Error loading image %s: %s\n", newFilename, IMG_GetError());
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, tmpSurface);
    if (texture == NULL) {
        printf("Error creating texture %s: %s\n", newFilename, SDL_GetError());
    }
    SDL_FreeSurface(tmpSurface);
    return texture;
}
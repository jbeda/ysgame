#include "TextureManager.hpp"
#include <stdio.h>
#include <SDL_image.h>
#include <string>
#include "Game.hpp"

SDL_Texture* TextureManager::LoadTexture(const char* filename) {
	std::string newFilenameStdStr = "assets\\" + (std::string)filename;
	const char* newFilename = newFilenameStdStr.c_str();
	SDL_Surface* tmpSurface = IMG_Load(newFilename);
	if (tmpSurface == NULL) {
		printf("Error loading image %s: %s\n", newFilename, IMG_GetError());
	}
	SDL_Texture* texture = gGame->renderer.CreateTextureFromSurface(tmpSurface);
	if (texture == NULL) {
		printf("Error creating texture %s: %s\n", newFilename, SDL_GetError());
	}
	SDL_FreeSurface(tmpSurface);
	return texture;
}
int TextureManager::Draw(SDL_Texture *texture, SDL_Rect src, SDL_Rect dest,
	double angle, SDL_RendererFlip flip) {
	return gGame->renderer.CopyEx(texture, &src, &dest, angle, NULL, flip);
}
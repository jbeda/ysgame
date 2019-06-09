#pragma once

#include <SDL.h>
#include <vector>
#include "Vector2D.hpp"

class YRenderer
{
public:
	YRenderer() : renderer(NULL), origin(0,0) {}
	~YRenderer() { Clean(); }

	void Clean() { SDL_DestroyRenderer(renderer); renderer = NULL; }

	void init(SDL_Renderer* r) { renderer = r; }

	SDL_Renderer* Get() { return renderer;  }

	int Clear() { return  SDL_RenderClear(renderer); }
	void Present() { SDL_RenderPresent(renderer); }
	int Copy(SDL_Texture* t, const SDL_Rect* srcrect, const SDL_Rect* dstrect) {
		return CopyEx(t, srcrect, dstrect, 0, NULL, SDL_FLIP_NONE);
	}
	int CopyEx(SDL_Texture* texture,
			const SDL_Rect* srcrect,
			const SDL_Rect* dstrect,
			const double angle,
			const SDL_Point* center,
			const SDL_RendererFlip flip);

	int FillRect(const SDL_Rect* rect);

	SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface) {
		return SDL_CreateTextureFromSurface(renderer, surface);
	}

	int SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
		return SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}

	void PushOrigin(Vector2f o) {
		contextStack.push_back(o);
		origin = origin + o;
	}
	void PopOrigin();

private:
	SDL_Renderer* renderer;

	Vector2f origin;
	std::vector<Vector2f> contextStack;
};


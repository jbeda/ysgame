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
		// adjust based on origin
		return SDL_RenderCopy(renderer, t, srcrect, dstrect);
	}
	int CopyEx(SDL_Texture* texture,
			const SDL_Rect* srcrect,
			const SDL_Rect* dstrect,
			const double angle,
			const SDL_Point* center,
			const SDL_RendererFlip flip) {
		// adjust based on origin
		return SDL_RenderCopyEx(renderer, texture, srcrect, dstrect, angle, center, flip);
	}

	int FillRect(const SDL_Rect* rect) {
		// adjust based on origin
		return SDL_RenderFillRect(renderer, rect);
	}

	SDL_Texture* CreateTextureFromSurface(SDL_Surface* surface) {
		return SDL_CreateTextureFromSurface(renderer, surface);
	}

	int SetDrawColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
		return SDL_SetRenderDrawColor(renderer, r, g, b, a);
	}

	void PushOrigin(Vector2f o) {
		// Take origin and push it on origins
		// Add origin to o
		// set origin to o
	}
	void PopOrigin() {
		// remove most recent from origins
		// set origin to that
		// error/assert if origins is empty
	}

private:
	SDL_Renderer* renderer;

	Vector2f origin;
	std::vector<Vector2f> origins;
};


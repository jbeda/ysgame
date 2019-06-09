#include "YRenderer.hpp"

int YRenderer::CopyEx(SDL_Texture* texture, const SDL_Rect* srcrect, const SDL_Rect* dstrect, const double angle, const SDL_Point* center, const SDL_RendererFlip flip) {
	// adjust based on origin
	auto adjrect = *dstrect;
	adjrect.x += origin.x;
	adjrect.y += origin.y;
	return SDL_RenderCopyEx(renderer, texture, srcrect, &adjrect, angle, center, flip);
}

int YRenderer::FillRect(const SDL_Rect* rect) {
	// adjust based on origin
	auto adjrect = *rect;
	adjrect.x += origin.x;
	adjrect.y += origin.y;
	return SDL_RenderFillRect(renderer, &adjrect);
}

void YRenderer::PopOrigin() {
	if (contextStack.size() <= 0) {
		printf("Error: Context stack underrun in YRenderer::PopOrigin();\n");
		return;
	}

	origin = contextStack.back();
	contextStack.pop_back();
}

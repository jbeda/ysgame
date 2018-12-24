#include "Form.hpp"
#include "../util/debugging/notif.h"
UIForm::UIForm(int x, int y, int w, int h) : GameObject(NULL, x, y, EUI) {
	this->activated = false;
	this->pos.x = x;
	this->pos.y = y;
	this->pos.w = w;
	this->pos.h = h;
}
void UIForm::Render() {
	if (this->activated) {
		YColor c = { 0,0,0,255 };
		gGame->SetRendererColor(c);
		SDL_RenderDrawRect(gGame->renderer, &this->pos);
	}
}
Widget::Widget(UIForm* parent, int pixRelativeX, int pixRelativeY, int pixW, int pixH, WidgetType type, std::string text, TTF_Font* font) : GameObject(NULL, parent->getPixX() + pixRelativeX, parent->getPixY() + pixRelativeY, EUI) {
	this->activated = false;
	this->destRect.w = pixW;
	this->destRect.h = pixH;
	this->parent = parent;
	this->type = type;
	SDL_Color c = {0,0,0,255};
	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), c);
	this->tText = SDL_CreateTextureFromSurface(gGame->renderer, surf);
	SDL_FreeSurface(surf);
	gWidgetIDs.push_back(std::unique_ptr<Widget>(this));
}
void Widget::Render() {
	if (this->activated)
		SDL_RenderCopy(gGame->renderer, this->tText, NULL, &this->destRect);
}
Widget::~Widget() {
	SDL_DestroyTexture(this->tText);
}
TTF_Font* Widget::Arial = NULL;
std::list<std::unique_ptr<Widget>> gWidgetIDs;
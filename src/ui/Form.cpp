#include "Form.hpp"
#include "../util/debugging/notif.h"
UIForm::UIForm(int x, int y, int w, int h, YColor c) : GameObject(NULL, x, y, EUI) {
	this->activated = false;
	this->pos.x = x;
	this->pos.y = y;
	this->pos.w = w;
	this->pos.h = h;
	//this->c = { c[0], c[1], c[2], c[3] };
}
void UIForm::Render() {
	if (this->activated) {
		YColor c = { this->c.r, this->c.g, this->c.b, this->c.a };
		gGame->SetRendererColor(c);
		SDL_RenderFillRect(gGame->renderer, &this->pos);
	}
}
Widget::Widget(UIForm* parent, int pixRelativeX, int pixRelativeY, int pixW, int pixH, WidgetType type, std::string text, TTF_Font* font, YColor c) : GameObject(NULL, parent->getPixX() + pixRelativeX, parent->getPixY() + pixRelativeY, EUI) {
	this->activated = false;
	this->destRect.w = pixW;
	this->destRect.h = pixH;
	this->parent = parent;
	this->type = type;
	SDL_Color co = {c[0],c[1],c[2],c[3]};
	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), co);
	this->tText = SDL_CreateTextureFromSurface(gGame->renderer, surf);
	SDL_FreeSurface(surf);
	gWidgetIDs.push_back(this);
}
void Widget::Render() {
	if (this->activated)
		SDL_RenderCopy(gGame->renderer, this->tText, NULL, &this->destRect);
}
Widget::~Widget() {
	SDL_DestroyTexture(this->tText);
	gWidgetIDs.remove(this);
}
TTF_Font* Widget::Arial = NULL;
std::list<Widget*> gWidgetIDs;
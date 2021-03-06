#include "Form.hpp"
#include "../util/debugging/notif.h"
UIForm::UIForm(int x, int y, int w, int h, YColor c) : SimpleGameObject(NULL, x, y, EUI) {
	this->activated = false;
	this->pos.x = x;
	this->pos.y = y;
	this->pos.w = w;
	this->pos.h = h;
	this->c = { c[0], c[1], c[2], c[3] };
}
void UIForm::Render() {
	if (this->activated) {
		YColor c = { this->c.r, this->c.g, this->c.b, this->c.a };
		gGame->SetRendererColor(c);
		gGame->renderer.FillRect(&this->pos);
	}
}
Widget::Widget(UIForm* parent, int pixRelativeX, int pixRelativeY, int pixH, WidgetType type, std::string text, TTF_Font* font, YColor c) : SimpleGameObject(NULL, parent->getPixX() + pixRelativeX, parent->getPixY() + pixRelativeY, EUI) {
	this->activated = false;
	this->destRect.w = pixH/2 * (std::strlen(text.c_str()) - 1);
	this->destRect.h = pixH;
	this->parent = parent;
	this->type = type;
	SDL_Color co = {c[0],c[1],c[2],c[3]};
	SDL_Surface* surf = TTF_RenderText_Solid(font, text.c_str(), co);
	this->tText = gGame->renderer.CreateTextureFromSurface(surf);
	SDL_FreeSurface(surf);
	gWidgetIDs.push_back(this);
}
void Widget::Render() {
	if (this->activated) {
		gGame->renderer.Copy(this->tText, NULL, &this->destRect);
	}
}
Widget::~Widget() {
	SDL_DestroyTexture(this->tText);
	gWidgetIDs.remove(this);
}
TTF_Font* Widget::Consolas = NULL;
std::list<Widget*> gWidgetIDs;
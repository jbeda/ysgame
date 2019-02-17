#pragma once
#include "../util/include.h"
#include "../GameObject.hpp"
#include "../Game.hpp"
#include <SDL_ttf.h>
enum WidgetType {
	WButton,
	WLabel,
	WTextEdit
};
class Widget;
extern std::list<Widget*> gWidgetIDs;
class UIForm;
class Widget : public GameObject {
public:
	Widget(UIForm* parent, int pixRelativeX, int pixRelativeY, int pixH, WidgetType type, std::string text, TTF_Font* font, YColor c);
	~Widget();
	void Render();
	void Activate() { this->activated = true; }
	void Deactivate() { this->activated = false; }
	UIForm* getParent() { return this->parent; }
	static TTF_Font* Consolas;
protected:
	WidgetType type;
	std::string text;
	UIForm* parent;
	bool activated;
	SDL_Texture* tText;
};
class UIForm : public GameObject {
public:
	UIForm(int pixX, int pixY, int pixW, int pixH, YColor c);
	void Activate() {
		this->activated = true;
		for (auto& widget : gWidgetIDs) {
			bool x = widget->getParent()->getPixX() == this->pos.x;
			bool y = widget->getParent()->getPixY() == this->pos.y;
			bool w = widget->getParent()->getPixW() == this->pos.w;
			bool h = widget->getParent()->getPixH() == this->pos.h;
			if (x && y && w && h)
				widget->Activate();
		}
	}
	void Deactivate() {
		this->activated = false;
		for (auto& widget : gWidgetIDs) {
			bool x = widget->getParent()->getPixX() == this->pos.x;
			bool y = widget->getParent()->getPixY() == this->pos.y;
			bool w = widget->getParent()->getPixW() == this->pos.w;
			bool h = widget->getParent()->getPixH() == this->pos.h;
			if (x && y && w && h)
				widget->Deactivate();
		}
	}
	void Render();
	int getPixX() { return this->pos.x; }
	int getPixY() { return this->pos.y; }
	int getPixW() { return this->pos.w; }
	int getPixH() { return this->pos.h; }
protected:
	SDL_Color c;
	SDL_Rect pos;
	bool activated;
};
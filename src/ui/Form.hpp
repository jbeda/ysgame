#pragma once
#include "../util/include.h"
#include "../GameObject.hpp"
enum WidgetType {
	WButton,
	WLabel,
	WTextEdit
};
class UIForm;
struct Widget {
	WidgetType type;
	std::string text, id;
	UIForm* parent;
};
class UIForm : public GameObject {
public:
	UIForm(int x, int y);
	void Add(Widget& w, int x, int y);
	void Remove(std::string& id);
};
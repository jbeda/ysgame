#include "Game.hpp"
#include "CompositeObject.hpp"
#include <SDL.h>
void CompositeObject::Update() {
	for (auto& o : this->objs) {
		o->Update();
	}
	this->objs.remove_if([](auto& o) { return o->IsDead(); });
}
void CompositeObject::Render() {
	gGame->renderer.PushOrigin(pos);
	for (auto& o : this->objs) {
		o->Render();
	}
	gGame->renderer.PopOrigin();
}
void CompositeObject::AddObject(GameObject* o) {
	this->objs.push_back(std::unique_ptr<GameObject>(o));
}

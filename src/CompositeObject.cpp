#include "CompositeObject.hpp"
#include <SDL.h>
void CompositeObject::Update() {
	for (auto& o : this->objs) {
		o->Update();
	}
	this->objs.remove_if([](auto& o) { return o->IsDead(); });
}
void CompositeObject::Render() {
	for (auto& o : this->objs) {
		o->Render(this->pos);
	}
}
void CompositeObject::AddObject(CompositeChild* o) {
	this->objs.push_back(std::unique_ptr<CompositeChild>(o));
}
void CompositeChild::Update() { }
void CompositeChild::Render(Vector2f pos) { }
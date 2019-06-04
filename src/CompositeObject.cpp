#include "CompositeObject.h"

void CompositeObject::Update()
{
	for (auto& o : this->objs) {
		o->Update();
	}

	this->objs.remove_if([](auto& o) { return o->IsDead(); });
}

void CompositeObject::Render()
{
	for (auto& o : this->objs) {
		o->Render();
	}
}

void CompositeObject::AddObject(GameObject* o)
{
	this->objs.push_back(std::unique_ptr<GameObject>(o));
}

#pragma once

#include <list>
#include <memory>

#include "GameObject.hpp"
#include "Vector2D.hpp"
class CompositeChild : public GameObject {
public:
	CompositeChild(EntityType type) : GameObject(type) { }
	virtual void Update();
	virtual void Render(Vector2f pos);
};
// A Composite Object has a list of children objects.  
// It manages the lifetime of those and sets a transform 
// so that they are rendered relative to the position of 
// the parent object.
class CompositeObject : public GameObject {
public:
	CompositeObject(Vector2f pos_) : GameObject(ECompositeObject), pos(pos_) {};
	virtual void Update();
	virtual void Render();
	void AddObject(CompositeChild* o);
private:
	std::list<std::unique_ptr<CompositeChild>> objs;
	Vector2f pos;
};

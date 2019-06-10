#pragma once

#include <list>
#include <memory>

#include "GameObject.hpp"
#include "Vector2D.hpp"

// A Composite Object has a list of children objects.  
// It manages the lifetime of those and sets a transform 
// so that they are rendered relative to the position of 
// the parent object.
class CompositeObject : public GameObject {
public:
	CompositeObject(Vector2f pos_) : GameObject(ECompositeObject), pos(pos_) {}
	virtual ~CompositeObject() {}

	virtual void Update();
	virtual void Render();

	// CompositeObject will take ownership of o
	void AddObject(GameObject* o);
private:
	std::list<std::unique_ptr<GameObject>> objs;
	Vector2f pos;
};

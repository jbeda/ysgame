#pragma once
class GameObject
{
public:
	GameObject() {}
	virtual ~GameObject() {}

	virtual void Update() {}
	virtual void Render() {}
	virtual bool IsDead() { return false; }
};


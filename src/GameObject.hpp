#pragma once

enum EntityType {
	EPlayer,
	EEnemy,
	EMap,
	EItem,
	EUI
};

class Enemy;

class GameObject
{
public:
	GameObject(EntityType type_) : type(type_) {}
	virtual ~GameObject() {}

	virtual void Update() {}
	virtual void Render() {}
	virtual bool IsDead() { return false; }
	EntityType getObjType() { return this->type; }

	Enemy* AsEnemy();

private:
	EntityType type;
};


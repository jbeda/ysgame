
#include "GameObject.hpp"
#include "Enemy.hpp"

Enemy* GameObject::AsEnemy() {
	if (getObjType() != EEnemy) { return NULL; }
	return dynamic_cast<Enemy*>(this);
}

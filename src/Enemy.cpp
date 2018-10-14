#include "Enemy.hpp"
#include "Player.hpp"
#include "Game.hpp"
void Enemy::Update() {
	SDL_Rect* plrLoc = Game::getPlr()->getLocation();
	if (this->destRect.x < plrLoc->x) {
		this->destRect.x++;
	} else if (this->destRect.x > plrLoc->x) {
		this->destRect.x--;
	}
	if (this->destRect.y < plrLoc->y) {
		this->destRect.y++;
	} else if (this->destRect.y > plrLoc->y) {
		this->destRect.y--;
	}
}
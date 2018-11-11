#include "Game.hpp"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "GameObject.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "PyxelMap.hpp"
#include "ArrayMap.hpp"
#include "Controller.hpp"
#include "XBOXController.hpp"
#include "items/Item.hpp"

YColor barrier = { 0, 0, 0, 0 };

Game* gGame = NULL;

void SetRendererColor(SDL_Renderer* ren, YColor color) {
	SDL_SetRenderDrawColor(ren, color[0], color[1], color[2], color[3]);
}

ReturnCode Game::init(const char* title, int x, int y, int w, int h, bool fullscreen) {
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
	if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_HAPTIC | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER)) != 0)
		throw "oops";
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! IMG_Init Error: %s\n", IMG_GetError());
		return CODE_RED;
	}
	playersController = new XBOXController(1);
	unsigned int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	wndw = SDL_CreateWindow(title, x, y, w, h, flags);
	if (wndw == NULL) {
		return CODE_RED;
	}
	renderer = SDL_CreateRenderer(wndw, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		SDL_DestroyWindow(wndw);
		return CODE_RED;
	}
	//map = new PyxelMap(std::string("outsidetiles"));

	this->map = new ArrayMap();
	this->plr = new Player();
	this->addObject(this->plr);
	this->addObject(new Wiper(10, 10));
	this->addObject(new Enemy(50, 50));
	return CODE_GREEN;
}

void Game::update() {
	for (auto& o : this->objs) {
		o->Update();
	}
}

void Game::render() {
	SetRendererColor(renderer, barrier);
	SDL_RenderClear(renderer);
	map->DrawMap();

	for (auto& o : this->objs) {
		if (!o->dead) {
			o->Render();
		}
	}

	SDL_RenderPresent(renderer);
}

void Game::garbageCollect() {
	this->objs.remove_if([](auto& o) { return o->dead; });
}

void Game::addObject(GameObject * obj) {
	this->objs.push_front(std::unique_ptr<GameObject>(obj));
}

void Game::clean() {
	delete playersController;
	delete map;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(wndw);
	IMG_Quit();
	SDL_Quit();
}
int Game::handleEvents() {
	SDL_Event e;
	if (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT)
			return EVENT_QUIT;
	}
	return EVENT_NOTHING;
}

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
SDL_Window* wndw;
Enemy* enemy1;
Map* map;
Controller* playersController;
Item* test;

void SetRendererColor(SDL_Renderer* ren, YColor color) {
	SDL_SetRenderDrawColor(ren, color[0], color[1], color[2], color[3]);
}

Game::Game(const char* title, int x, int y, int w, int h, bool fullscreen) {
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
	if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_HAPTIC | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER)) != 0)
		throw "oops";
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! IMG_Init Error: %s\n", IMG_GetError());
		this->rtrnVal = CODE_RED;
	}
	playersController = new XBOXController(1);
	unsigned int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	wndw = SDL_CreateWindow(title, x, y, w, h, flags);
	if (wndw == NULL) {
		this->rtrnVal = CODE_RED;
		return;
	}
	renderer = SDL_CreateRenderer(wndw, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		SDL_DestroyWindow(wndw);
		this->rtrnVal = CODE_RED;
		return;
	}
	//map = new PyxelMap(std::string("outsidetiles"));
	map = new ArrayMap();
	plr = new Player();
	test = new Grenade(10, 10);
	enemy1 = new Enemy(50, 50);
	this->rtrnVal = CODE_GREEN;
}

void Game::update() {
	plr->Update();
	plr->sw->Update();
	if (!enemy1->dead)
		enemy1->Update();
	if (!test->dead)
		test->Update();
}

void Game::render() {
	SetRendererColor(renderer, barrier);
	SDL_RenderClear(renderer);
	map->DrawMap();
	plr->Render();
	plr->sw->Render();
	if (!enemy1->dead)
		enemy1->Render();
	if (!test->dead)
		test->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	delete playersController;
	delete map;
	delete plr;
	delete enemy1;
	delete test;
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
Controller* Game::getPlrController() {
	return playersController;
}
SDL_Renderer* Game::renderer = NULL;
Player* Game::plr = NULL;
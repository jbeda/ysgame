#include "Game.hpp"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "GameObject.hpp"
#include "Player.hpp"
#include "PyxelMap.hpp"
#include "ArrayMap.hpp"
#include "Controller.hpp"
#include "XBOXController.hpp"

int bgcolor[] = {255, 255, 255, 255};
SDL_Window* wndw;
GameObject* enemy1;
Map* map;
Controller* playersController;

Game::Game(const char* title, int x, int y, int w, int h, bool fullscreen) {
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
	if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_HAPTIC|SDL_INIT_JOYSTICK|SDL_INIT_GAMECONTROLLER)) != 0)
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
 
    this->plr = new Player();
    enemy1 = new GameObject("Enemy.png", 50, 50);
    this->rtrnVal = CODE_GREEN;
}

void Game::update() {
    this->plr->Update();
    enemy1->Update();
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, bgcolor[0], bgcolor[1], bgcolor[2], bgcolor[3]);
    SDL_RenderClear(renderer);
    map->DrawMap();
    this->plr->Render();
    enemy1->Render();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
	delete playersController;
    delete map;
    delete this->plr;
    delete enemy1;
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
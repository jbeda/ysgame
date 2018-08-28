#include "Game.hpp"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "GameObject.hpp"

int bgcolor[] = {0, 255, 255, 255};
SDL_Window* wndw;
SDL_Renderer* ren;
GameObject* enemy1;

Game::Game(const char* title, int x, int y, int w, int h, bool fullscreen) {
    SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
    SDL_Init(SDL_INIT_EVERYTHING);
    
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! IMG_Init Error: %s\n", IMG_GetError());
        this->rtrnVal = CODE_RED;
    }

    unsigned int flags = 0;
    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;
    wndw = SDL_CreateWindow(title, x, y, w, h, flags);
    if (wndw == NULL) {
        this->rtrnVal = CODE_RED;
        return;
    }
    ren = SDL_CreateRenderer(wndw, -1, SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL) {
        SDL_DestroyWindow(wndw);
        this->rtrnVal = CODE_RED;
        return;
    }
    this->plr = new GameObject("Player.png", 0, 0, ren);
    enemy1 = new GameObject("Enemy.png", 50, 50, ren);
    this->rtrnVal = CODE_GREEN;
}
void Game::update() {
    this->plr->Update();
    enemy1->Update();
}

void Game::render() {
    SDL_SetRenderDrawColor(ren, bgcolor[0], bgcolor[1], bgcolor[2], bgcolor[3]);
    SDL_RenderClear(ren);

    this->plr->Render();
    enemy1->Render();

    SDL_RenderPresent(ren);
}

void Game::clean() {
    delete this->plr;
    delete enemy1;
    SDL_DestroyRenderer(ren);
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

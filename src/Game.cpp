#include "Game.hpp"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include "Character.hpp"
int bgcolor[] = {0, 255, 255, 255};
SDL_Window* wndw;
SDL_Renderer* ren;
Character plr;
Game::Game(const char* title, int x, int y, int w, int h, bool fullscreen) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    plr = Character("assets\\Player.png", 0, 0, 15, 15, ren);
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
}
void Game::update() {
    this->count++;
    plr.setX(this->count);
}
void Game::clean() {
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
void Game::render() {
    SDL_SetRenderDrawColor(ren, bgcolor[0], bgcolor[1], bgcolor[2], bgcolor[3]);
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, plr.getImage(), NULL, plr.getLocation());
    SDL_RenderPresent(ren);
}
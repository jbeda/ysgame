#include "Game.hpp"
#include <SDL.h>
#include <stdio.h>
SDL_Window* wndw;
SDL_Renderer* ren;
Game::Game(const char* title, int x, int y, int w, int h, bool fullscreen) {
    SDL_Init(SDL_INIT_EVERYTHING);
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
void Game::update() { }
void Game::clean() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(wndw);
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
void Game::render() { }
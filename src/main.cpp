#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include "Game.hpp"

#define FPS 60 // for now
#define FRAME_DELAY 1000 / FPS

int main(int argc, char const *argv[]) {
    Game* game = new Game("ys-game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

    ReturnCode color = game->constrReturnValue();
    if (color == CODE_RED) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    while (1) {
        Uint32 frameStart = SDL_GetTicks();
        game->update();
        game->render();
        int code = game->handleEvents();
        if (code == EVENT_QUIT)
            break;
        int frameTime = SDL_GetTicks() - frameStart;
        if (FRAME_DELAY > frameTime) {
            SDL_Delay(FRAME_DELAY - frameTime);
        }
    }
    game->clean();
    delete game;
    return 0;
}

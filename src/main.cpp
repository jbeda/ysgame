#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <stdio.h>
#include "Game.hpp"
#include "Character.hpp"

int main(int argc, char const *argv[]) {
    Game* game = new Game("ys-game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, false);

    ReturnCode color = game->constrReturnValue();
    if (color == CODE_RED) {
        printf("Error: %s\n", SDL_GetError());
        return 1;
    }

    while (1) {
        game->update();
        game->render();
        int code = game->handleEvents();
        if (code == EVENT_QUIT)
            break;
    }
    game->clean();
    delete game;
    return 0;
}

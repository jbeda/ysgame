#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
typedef int YColor[4];
class Player;
class Controller;

// WINDOW SIZE
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT WINDOW_WIDTH

// EVENT CODES
#define EVENT_QUIT 0x1
#define EVENT_NOTHING 0x0

// RETURN CODES
typedef int ReturnCode;

#define CODE_GREEN 0x00FF00
#define CODE_RED 0xFF0000

class Game {
public:
    Game(const char*, int, int, int, int, bool);
    int handleEvents();
    void clean();
    void update();
    void render();
    ReturnCode constrReturnValue() { return this->rtrnVal; }
    static SDL_Renderer* renderer;
	static Controller* getPlrController();
	static Player* getPlr() { return plr; }
private:
    ReturnCode rtrnVal;
	static Player *plr;
};
#endif
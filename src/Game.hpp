#ifndef GAME_HPP
#define GAME_HPP

class Character;

// WINDOW SIZE
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

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
private:
    int count;
    ReturnCode rtrnVal;
    Character plr;
};
#endif
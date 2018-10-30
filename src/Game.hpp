#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
#include "GameObject.hpp"

#include <list>
#include <memory>

typedef int YColor[4];
class GameObject;
class Player;
class Controller;
class Map;

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
	Game() {};
	ReturnCode init(const char* title, int x, int y, int w, int h, bool fullscreen);

	int handleEvents();
	void clean();
	void update();
	void render();
	void garbageCollect();

	SDL_Renderer* renderer;
	Controller* getPlrController() { return playersController;  }
	Player* getPlr() { return plr; }

	void addObject(GameObject* obj);

private:
	Controller* playersController = NULL;
	std::list<std::unique_ptr<GameObject>> objs;
	Player *plr = NULL;
	Map* map = NULL;
	SDL_Window* wndw= NULL;

};

extern Game* gGame;
#endif
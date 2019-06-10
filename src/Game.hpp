#ifndef GAME_HPP
#define GAME_HPP

#include <SDL.h>
#include "SimpleGameObject.hpp"
#include "input/InputManager.hpp"
#include "YRenderer.hpp"

#include <list>
#include <memory>
#include <random>

// DEFINITIONS
typedef Uint8 YColor[4];
class SimpleGameObject;
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

#define PI 3.14159265

class Game {
public:
	Game() {};
	ReturnCode init(const char* title, int x, int y, int w, int h, bool fullscreen);

	int handleEvents();
	void clean();
	void update();
	void render();
	void garbageCollect();


	YRenderer renderer;
	void SetRendererColor(YColor color);
	Player* getPlr() { return plr; }
	InputManager* getInput() { return input; }
	void addObject(GameObject* obj);
	std::list<std::unique_ptr<GameObject>>& getObjectList() { return this->objs; }
	Map* getMap() { return this->map; }

	float Random(float min = 0.0f, float max = 1.0f) {
		std::uniform_real_distribution<float> distribution(min, max);
		return distribution(randGen);
	}
private:
	std::list<std::unique_ptr<GameObject>> objs;
	Player *plr = NULL;
	Map* map = NULL;
	SDL_Window* wndw = NULL;
	InputManager* input = NULL;
	std::default_random_engine randGen;
};

extern Game* gGame;
#endif
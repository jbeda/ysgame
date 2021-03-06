#include "Game.hpp"
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "sound/Sound.hpp"
#include "ui/Form.hpp"
#include "SimpleGameObject.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "PyxelMap.hpp"
#include "ArrayMap.hpp"
#include "input/Controller.hpp"
#include "input/XBOXController.hpp"
#include "items/Item.hpp"
#include "ParticleSystem.hpp"

Music* lvl1music = NULL;

Game* gGame = NULL;

void Game::SetRendererColor(YColor color) {
	this->renderer.SetDrawColor(color[0], color[1], color[2], color[3]);
}

ReturnCode Game::init(const char* title, int x, int y, int w, int h, bool fullscreen) {
#ifdef DEBUGENABLED
	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);
#endif

	// Initialize the Random Number Generator
	std::random_device rd;
	randGen.seed(rd());

	if (SDL_Init(SDL_INIT_EVERYTHING & ~(SDL_INIT_HAPTIC | SDL_INIT_JOYSTICK | SDL_INIT_GAMECONTROLLER)) != 0)
	{
		printf("SDL_Init could not initialize! Error: %s\n", SDL_GetError());
		return CODE_RED;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! IMG_Init Error: %s\n", IMG_GetError());
		return CODE_RED;
	}
	if (TTF_Init() != 0) {
		printf("SDL_ttf could not initialize! TTF_Init Error: %s\n", TTF_GetError());
		return CODE_RED;
	}
	Widget::Consolas = TTF_OpenFont("C:\\Windows\\Fonts\\Consola.ttf", 12);
	if (Widget::Consolas == NULL) {
		printf("Could not load Arial font! TTF_OpenFont Error: %s\n", TTF_GetError());
		return CODE_RED;
	}
	int mixerFlags = MIX_INIT_MP3 | MIX_INIT_OGG;
	if (Mix_Init(mixerFlags) != mixerFlags) {
		printf("SDL_mixer could not initialize! Mix_Init Error: %s\n", Mix_GetError());
		return CODE_RED;
	}
	Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
	input = new InputManager();
	input->init();

	unsigned int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	wndw = SDL_CreateWindow(title, x, y, w, h, flags);
	if (wndw == NULL) {
		return CODE_RED;
	}
	SDL_Surface* tempsurf = IMG_Load("assets\\Player.png");
	SDL_SetWindowIcon(wndw, tempsurf);
	SDL_FreeSurface(tempsurf);
	auto r = SDL_CreateRenderer(wndw, -1, SDL_RENDERER_PRESENTVSYNC);
	if (r == NULL) {
		SDL_DestroyWindow(wndw);
		return CODE_RED;
	}
	SDL_SetRenderDrawBlendMode(r, SDL_BLENDMODE_BLEND);
	renderer.init(r);
	//map = new PyxelMap(std::string("outsidetiles"));
	this->map = new ArrayMap();
	this->plr = new Player();
	this->addObject(this->plr);
	this->addObject(new Enemy(50, 50));
	this->addObject(new ParticleSystem(Vector2f(50, 50), 100, 1));
	// test items {
	this->addObject(new RapidThrowInit(4, 4));
	this->addObject(new HomingKnifeInit(6, 4));
	// }
	SoundEffect::LoadSFX();
	lvl1music = Music::LoadMP3("assets/tutorialmusic.mp3");
	Music::PlayMP3(lvl1music, -1);
	return CODE_GREEN;
}

void Game::update() {
	input->update();

	for (auto& o : this->objs) {
		o->Update();
	}
}

void Game::render() {
	renderer.Clear();
	map->DrawMap();

	for (auto& o : this->objs) {
		if (!o->IsDead()) {
			o->Render();
		}
	}

	renderer.Present();
}

void Game::garbageCollect() {
	this->objs.remove_if([](auto& o) { return o->IsDead(); });
}

void Game::addObject(GameObject * obj) {
	this->objs.push_front(std::unique_ptr<GameObject>(obj));
}

void Game::clean() {
	TTF_CloseFont(Widget::Consolas);
	delete input;
	delete map;
	Music::StopMP3();
	Music::UnloadMP3(lvl1music);
	SoundEffect::UnloadSFX();
	renderer.Clean();
	SDL_DestroyWindow(wndw);
	Mix_CloseAudio();
	Mix_Quit();
	TTF_Quit();
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
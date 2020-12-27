#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "texture_manager.h"
#include "entity_manager.h"
#include "entity.h"
#include <vector>
#include <iostream>

class Game {
private:

	int cnt = 0;
	bool isRunning;
	SDL_Window* window;


	//static SDL_Event event;

public:
	Entity_manager manager;
	static SDL_Renderer* renderer;
	static SDL_Event event;
	Game();
	Game(const char* tittle, int xpos, int ypos, int width, int height, bool fullscreen);
	~Game();


	void handle_event();
	void update();
	bool running() { return isRunning; }
	void render();
	void re_run();

};
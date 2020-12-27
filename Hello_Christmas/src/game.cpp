#include "game.h"
#include <cstdlib>


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game() {

}

Game::~Game() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game Cleaner" << std::endl;
}

Game::Game(const char* tittle, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initalied!" << std::endl;

		window = SDL_CreateWindow(tittle, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {

			SDL_SetRenderDrawColor(renderer, 66, 0, 132, 0);
			std::cout << "Renderer created!" << std::endl;
		}
		manager.add_entity(100, ground, 1, 0, 0, 3);
		isRunning = true;
	}
	
}


void Game::handle_event() {
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT) {
		isRunning = false;
	}
}

void Game::update() {
	if (rand() % 2 == 0) {
		manager.add_entity(rand() % 1200, 0, 0, 0, 5 + (double)(rand() % 4) , 1);
	}

	manager.refresh();
	manager.update();
}

void Game::render() {
	SDL_RenderClear(renderer);//사이에 넣을 것

	manager.draw();

	SDL_RenderPresent(renderer);

}


void Game::re_run() {
	isRunning = true;
}
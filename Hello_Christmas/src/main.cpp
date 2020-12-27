#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SDL.h"
#include "game.h"

Game* game;

int main(int argc, char* argv[]) {
	srand((unsigned int)time(NULL));
	const int FPS = 30;//frame per second
	const int frame_delay = 1000 / FPS;

	Uint32 frame_start;
	int frame_time;

	game = new Game("Hello Christmas!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, false);
	while (1) {
		while (game->running()) {

			frame_start = SDL_GetTicks();

			game->update();
			game->render();

			frame_time = SDL_GetTicks() - frame_start;

			if (frame_delay > frame_time) {
				SDL_Delay(frame_delay - frame_time);
			}

			game->handle_event();
		}
		game->re_run();
	}
	//delete game;

	return 0;
}



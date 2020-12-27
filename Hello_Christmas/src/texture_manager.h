#pragma once
#include "game.h"

class Texture_manager {
public:
	static SDL_Texture* Load_texture(const char* name);
	static void Draw(SDL_Texture* tex, SDL_Rect& src, SDL_Rect& dest);
};

#include "texture_manager.h"

SDL_Texture* Texture_manager::Load_texture(const char* name) {
	SDL_Surface* tmpSurface = IMG_Load(name);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);//surface로부터 텍스처를 만든다.
	SDL_FreeSurface(tmpSurface);

	return texture;
}

void Texture_manager::Draw(SDL_Texture* tex, SDL_Rect& src, SDL_Rect& dest) {
	//랜더링 중인 텍스쳐를 카피함 > 난 덮어쓰기를 할 거임!
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}


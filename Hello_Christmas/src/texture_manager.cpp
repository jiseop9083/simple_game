#include "texture_manager.h"

SDL_Texture* Texture_manager::Load_texture(const char* name) {
	SDL_Surface* tmpSurface = IMG_Load(name);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);//surface�κ��� �ؽ�ó�� �����.
	SDL_FreeSurface(tmpSurface);

	return texture;
}

void Texture_manager::Draw(SDL_Texture* tex, SDL_Rect& src, SDL_Rect& dest) {
	//������ ���� �ؽ��ĸ� ī���� > �� ����⸦ �� ����!
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}


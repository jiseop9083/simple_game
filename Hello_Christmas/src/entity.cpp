#include "entity.h"
#include "SDL.h"
#include "texture_manager.h"


Entity::Entity(double xpos, double ypos, double xvel, double yvel, double gra)
	: pos(xpos, ypos), vel(xvel, yvel), gravity(gra), active(true), type(0), direction(true) {
	dest.x = static_cast<int>(pos.getX());
	//dest.y = static_cast<int>(pos.getY());

}

Entity::~Entity() {};

void Entity::draw() {
	Texture_manager::Draw(texture, src, dest);
}

void Entity::update() {
	vel.setY(vel.getY() + gravity);
	pos += vel;
	if (pos.getY() >= ground) {
		vel.restart(vel.getX(), 0);
		pos.restart(vel.getX(), ground - (double)dest.h);
	}
	
}

Santa::Santa(const char* path, double xpos, double ypos, double xvel, double yvel, double scale, double gra)
	: Entity(xpos, ypos, xvel, yvel, gra), dance_type(6), is_jumping(false), cnt(0), delay(0) {
	texture = Texture_manager::Load_texture(path);
	dest.y = (int)(pos.getY() - scale * 64);
	dest.w = (int)(64 * scale);
	dest.h = (int)(64 * scale);
	src.x = 64 * dance_type;
	src.y = 0;
	src.w = 64;
	src.h = 64;
}

void Santa::update() {
	cnt++;
	if (delay > 0) {
		delay--;
	}
	if (Game::event.type == SDL_KEYDOWN) {
		
		switch (Game::event.key.keysym.sym) {
		case SDLK_w:
			if (is_jumping == false) {
				vel.setY(-75);
				is_jumping = true;
				
			}
			break;
		case SDLK_a:
			vel.setX(-10);
			direction = false;
			break;
		case SDLK_d:
			vel.setX(10);
			direction = true;
			break;

		case SDLK_SPACE:
			if (delay == 0) {
				delay = -1;
			}
			break;
		default:
			
			break;
		}
	}
	vel.setY(vel.getY() + gravity);
	pos += vel;
	if (pos.getY() > ground - (double)dest.h) {
		vel.setY(0);
		pos.setY(ground - (double)dest.h);
		is_jumping = false;
	}
	

	if (Game::event.type == SDL_KEYUP) {
		switch (Game::event.key.keysym.sym) {
		case SDLK_a:
			if (is_jumping == false) {
				vel.setX(0);
			}
			break;
		case SDLK_d:
			if (is_jumping == false) {
				vel.setX(0);
			}
			break;
		case SDLK_SPACE:
			if (delay == -1) {
				delay = 1;
				type = 1;
				if (direction == true) {
					dance_type = 7;
				}
				else {
					dance_type = 8;
				}
			}
			break;
		default:
			break;
		}
	}
	dest.x = (int)pos.getX();
	dest.y = (int)pos.getY();
	if (cnt >= 8) {
		cnt = 0;
		if (dance_type <= 5) {
			dance_type = (dance_type + 1) % 6;
		}
		else {
			dance_type = 0;
		}
	}
	if (vel.getY() != 0) {
		dance_type = 6;
	}
	src.x = 64 * dance_type;

}

Snow::Snow(const char* path, double xpos, double ypos, double xvel, double yvel, double scale, double gra) :
	Entity(xpos, ypos, xvel, yvel, gra), wave(0) {
	texture = Texture_manager::Load_texture(path);
	dest.y = (int)(pos.getY() - scale * 64);
	dest.w = (int)(16 * scale);
	dest.h = (int)(16 * scale);
	src.x = 0;
	src.y = 0;
	src.w = 16;
	src.h = 16;
}

void Snow::update() {
	vel.setY(vel.getY() + gravity);
	pos += vel;
	if (pos.getY() >= ground - (double)dest.h) {
		active = false;
	}
	wave += 1;
	
	dest.x = pos.getX();
	dest.y = pos.getY();
}

Present::Present(const char* path, double xpos, double ypos, double xvel, double yvel, double scale, double gra) :
	Entity(xpos, ypos, xvel, yvel, gra), cnt(100) {
	texture = Texture_manager::Load_texture(path);
	dest.y = (int)(pos.getY() - scale * 64);
	dest.w = (int)(64* scale);
	dest.h = (int)(64 * scale);
	src.x = 0;
	src.y = 0;
	src.w = 64;
	src.h = 64;
}


void Present::update() {
	cnt--;
	
	vel.setY(vel.getY() + gravity);
	pos += vel;
	if (pos.getY() >= ground - (double)dest.h) {
		pos.setY(ground - (double)dest.h);
		vel.setX(0);
	}
	dest.x = pos.getX();
	dest.y = pos.getY();
	if (cnt == 0) {
		active = false;
	}
}

std::pair<bool, std::pair<double, double>>  Entity::getInfo() {
	std::pair<bool, std::pair<double, double>> re = { direction,{pos.getX(), pos.getY() } };
	return re;
}

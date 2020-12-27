#pragma once
#include <vector>
#include "rect_coordinate.h"
#include "SDL.h"
#include <cmath>

//나중에 없앨 것, main에 정의할 것
const int ground = 800;

class Entity {
protected:
	Rect_co pos;
	Rect_co vel;
	double gravity;
	SDL_Texture* texture;
	SDL_Rect src, dest;
	bool active;
	bool direction;

public:
	int type;
	bool isActive() { return active; }
	Entity() :gravity(0), pos(0.0, ground), vel(0.0, ground), active(true) {};
	Entity(double xpos, double ypos, double xvel, double yvel, double gra);
	virtual ~Entity() = 0;
	virtual void update() = 0;
	void draw();
	int getType() { return type; }
	std::pair<bool, std::pair<double, double>> getInfo();
};

class Santa : public Entity {
private:
	int dance_type;
	bool is_jumping;
	int cnt;
	
	int delay;
public:
	Santa(const char* path, double xpos, double ypos, double xvel, double yvel, double scale, double gra);
	virtual ~Santa() {}
	virtual void update();
};

class Snow : public Entity {
private:
	double wave;
public:
	Snow(const char* path, double xpos, double ypos, double xvel, double yvel, double scale, double gra);
	virtual ~Snow() {}
	virtual void update();

};

class Present : public Entity {
private:
	int cnt;
public:
	Present(const char* path, double xpos, double ypos, double xvel, double yvel, double scale, double gra);
	virtual ~Present() {}
	virtual void update();
};

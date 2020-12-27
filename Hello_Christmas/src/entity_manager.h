#pragma once
#include <vector>
#include "entity.h"

class Entity_manager {
private:
	std::vector<Entity*> entities;
public:
	Entity_manager();
	~Entity_manager();
	void update();
	void draw();
	void refresh();
	bool add_entity(double xpos, double ypos, int type, double xvel = 0, double yvel = 0, double scale = 0);
	int get_size();
};
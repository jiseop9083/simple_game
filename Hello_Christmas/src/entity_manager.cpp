
#include <vector>
#include "entity_manager.h"

Entity_manager::Entity_manager() {

}

Entity_manager::~Entity_manager() {

}

bool Entity_manager::add_entity(double xpos, double ypos, int type, double xvel, double yvel, double scale) {
	switch (type) {
	case 0: //snow
		entities.push_back(new Snow("assets/snow.png", xpos, ypos, xvel, yvel, scale, 0));
		break;
	case 1: //santa
		entities.push_back(new Santa("assets/santa_dance.png", xpos, ypos, xvel, yvel, scale, 9.8));
		break;
	case 2: //present
		entities.push_back(new Present("assets/present.png", xpos, ypos, xvel, yvel, scale, 9.8));
		break;
	}
	return true;
}

void Entity_manager::update() {
	bool check = false;
	std::pair<int, std::pair<double, double>> temp;
	for (auto e : entities) {
		e->update();
		if (e->type == 1) {
			check = true;
			e->type = 0;
			temp = e->getInfo();
		}
	}
	if (check == true) {
		if (temp.first == true) {
			add_entity(temp.second.first + 64, temp.second.second, 2, 10, -70, 2);
		}
		else {
			add_entity(temp.second.first, temp.second.second, 2, -10, -70, 2);
		}
	}
}

void Entity_manager::draw() {
	for (auto e : entities) {
		e->draw();
		
	}
}
void Entity_manager::refresh() {
	entities.erase(std::remove_if(std::begin(entities), std::end(entities),
		[](Entity* m)
		{
			return !(m->isActive());
		}),//람다함수
		std::end(entities));
}

int Entity_manager::get_size() {
	return entities.size();
}
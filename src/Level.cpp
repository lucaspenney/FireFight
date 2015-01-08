#include "Level.h"
#include "Player.h"

Level::Level()
{

}


Level::~Level()
{
}

void Level::render(Renderer* renderer) {
	for(std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
		(*it)->render(renderer);
	}
}

void Level::update() {
	for(std::vector<Entity*>::iterator it = entities.begin(); it != entities.end(); ++it) {
		(*it)->update();
	}
}

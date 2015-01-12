#pragma once

#include "Renderer.h"

#include <vector>
class Entity;
class Level;
class Player;
class Game 
{
public:
	Game();
	~Game();
	Level* level;
	void update();
	void render(Renderer* renderer);
	std::vector<Entity*> entities;
	Player* player;
private:

};

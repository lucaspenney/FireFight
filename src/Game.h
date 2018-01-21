#pragma once

#include "Renderer.h"

#include <vector>
#include <unistd.h>
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
	double getTimeMs();
	std::vector<Entity*> entities;
	Player* player;
	long tick = 0;
private:

};

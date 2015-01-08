#pragma once
#include "Renderer.h"
#include "Entity.h"
#include <vector>
class Level
{
public:
	Level();
	~Level();
	
	std::vector<Entity*> entities;
	
	void render(Renderer* renderer);
	void update();
};


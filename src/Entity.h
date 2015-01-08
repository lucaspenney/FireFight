#pragma once
#include "Renderer.h"
class Entity
{
public:
	Entity();
	~Entity();
	virtual void render(Renderer* renderer);
	virtual void update();
};


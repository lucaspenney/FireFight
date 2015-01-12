#pragma once
class Entity;

#include "Renderer.h"
#include "Game.h"
class Game;
class Entity
{
public:
	Entity();
	~Entity();
	virtual void render(Renderer* renderer);
	virtual void update(Game* game);
};


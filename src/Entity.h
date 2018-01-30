#pragma once
class Entity;

#include "Renderer.h"
#include "Game.h"
#include "Vector2.h"

class Entity
{
public:
	Entity();
	~Entity();
	virtual void render(Renderer* renderer);
	virtual void update(Game* game);

protected:
	Vector2 position;
};

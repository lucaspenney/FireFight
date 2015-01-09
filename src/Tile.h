#pragma once
#include "Renderer.h"

class Tile
{
public:
	Tile(int x, int y);
	~Tile();
	int x, y;
	void render(Renderer* renderer);
};


#pragma once
#include "Renderer.h"
#include "BoundingBox.h"
#include <SFML/Graphics.hpp>
class Tile
{
public:
	Tile(int id, int x, int y);
	~Tile();
	int id;
	int x, y;
	bool solid = false;
	sf::Sprite sprite;
	BoundingBox* boundingBox;
	void render(Renderer* renderer);
};


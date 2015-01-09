#pragma once
#include "Renderer.h"
#include <SFML/Graphics.hpp>
class Tile
{
public:
	Tile(int id, int x, int y);
	~Tile();
	int id;
	int x, y;
	sf::Sprite sprite;
	void render(Renderer* renderer);
};


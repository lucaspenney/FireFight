#include "Tile.h"
#include <SFML/Graphics.hpp>

Tile::Tile(int x, int y)
{
	this->x = x;
	this->y = y;
}


Tile::~Tile()
{
}

void Tile::render(Renderer* renderer) {
	sf::CircleShape shape(20);
	shape.setPosition(x*32, y*32);
	shape.setFillColor(sf::Color(50, 100, 50));
	renderer->getWindow()->draw(shape);
}
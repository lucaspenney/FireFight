#include "Tile.h"
#include "AssetManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>
Tile::Tile(int id, int x, int y)
{
	id--;
	this->id = id;
	this->x = x;
	this->y = y;
	sprite.setTexture(AssetManager::textures["tilesheet"]);
	int xTile = (id % 16) * 32;
	int yTile = (id / 16) * 32;
	sprite.setTextureRect(sf::IntRect(xTile, yTile, 32, 32));
	boundingBox = new BoundingBox(x, y, 32, 32);
}


Tile::~Tile()
{
}

void Tile::render(Renderer* renderer) {
	renderer->drawSprite(sprite, x, y);
}
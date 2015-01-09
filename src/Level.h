#pragma once
#include "Renderer.h"
#include "Entity.h"
#include "Tile.h"

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class Level
{
public:
	Level();
	~Level();

	sf::Sprite spriteSheet;
	
	std::vector<Entity*> entities;
	std::vector<Tile*> tiles;

	int width;
	int height;
	
	void render(Renderer* renderer);
	void update();
	bool loadLevelFile(std::string filePath);
};


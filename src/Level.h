#pragma once

#include "Renderer.h"
#include "Entity.h"
#include "Tile.h"
#include "Game.h"

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
class Game;
class Level
{
public:
	Level();
	~Level();

	sf::Sprite spriteSheet;

	std::vector<Tile*> tiles;

	int width;
	int height;
	
	void render(Renderer* renderer);
	void update(Game* game);
	bool loadLevelFile(std::string filePath);
};


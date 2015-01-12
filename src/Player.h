#pragma once
#include "Entity.h"
#include "BoundingBox.h"
#include <SFML/Graphics.hpp>
class Player : public Entity
{
public:
	Player();
	~Player();
	int x = 0;
	int y = 0;
	sf::Sprite sprite;
	sf::View view;
	BoundingBox* boundingBox;
	virtual void render(Renderer* renderer);
	virtual void update(Game* game);
	
	private:
		
};


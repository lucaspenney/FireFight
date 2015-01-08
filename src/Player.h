#pragma once
#include "Entity.h"
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
	virtual void render(Renderer* renderer);
	virtual void update();
	
	private:
		
};


#pragma once
#include <SFML/Graphics.hpp>
class Menu
{
public:
	Menu();
	~Menu();
	bool isOpen();
	sf::Sprite sprite;
private:
	sf::Texture texture;
	
};


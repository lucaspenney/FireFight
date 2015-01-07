#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
class InputManager
{
public:
	InputManager(sf::RenderWindow* window);
	~InputManager();
	void handleInput();
private:
	sf::RenderWindow* mRenderWindow;
};


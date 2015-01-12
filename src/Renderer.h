#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Renderer
{
public:
	Renderer(int width, int height, sf::RenderWindow* renderWindow);
	~Renderer();
	void drawSprite(sf::Sprite sprite, int x, int y);
	void setView(sf::View* view);
	sf::RenderWindow* getWindow();
private:
	int mScreenWidth;
	int mScreenHeight;
	sf::RenderWindow* mRenderWindow;
};


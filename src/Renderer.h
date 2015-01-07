#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
class Renderer
{
public:
	Renderer(int width, int height, sf::RenderWindow* renderWindow);
	void drawSprite(sf::Sprite sprite, int x, int y);
	~Renderer();
private:
	int mScreenWidth;
	int mScreenHeight;
	sf::RenderWindow* mRenderWindow;
};


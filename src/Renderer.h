#pragma once

#include <map>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>

using std::string;
using std::map;

class Renderer
{
public:
	Renderer(int width, int height, sf::RenderWindow* renderWindow);
	~Renderer();
	void drawSprite(sf::Sprite sprite, int x, int y);
	void setView(sf::View* view);
	sf::RenderWindow* getWindow();
	map<string, sf::Font*> fonts;
private:
	int mScreenWidth;
	int mScreenHeight;
	sf::RenderWindow* mRenderWindow;
};

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
	Renderer(int screenWidth, int screenHeight, int viewWidth, int viewHeight, sf::RenderWindow* renderWindow);
	~Renderer();
	void drawSprite(sf::Sprite sprite, int x, int y);
	void setWindowSize(int width, int height);
	void setView(sf::View view);
	sf::RenderWindow* getWindow();
	sf::View getView();
	void setViewPosition(float x, float y);
	map<string, sf::Font*> fonts;
	int mScreenWidth;
	int mScreenHeight;
	int mViewWidth;
	int mViewHeight;
private:
	sf::RenderWindow* mRenderWindow;
	sf::View mActiveView;
};

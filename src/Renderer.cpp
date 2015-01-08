#include "Renderer.h"

Renderer::Renderer(int width, int height, sf::RenderWindow* renderWindow)
{
	mScreenWidth = width;
	mScreenHeight = height;
	mRenderWindow = renderWindow;
}

Renderer::~Renderer()
{
}

void Renderer::drawSprite(sf::Sprite sprite, int x, int y) {
	sprite.setPosition(x, y);
	mRenderWindow->draw(sprite);
}

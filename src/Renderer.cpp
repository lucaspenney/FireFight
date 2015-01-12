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

void Renderer::setView(sf::View* view) {
	view->setSize(mScreenWidth, mScreenHeight);
	view->zoom(0.5f);
	mRenderWindow->setView(*view);
}

sf::RenderWindow* Renderer::getWindow() {
	return mRenderWindow;
}

#include "Renderer.h"

Renderer::Renderer(int width, int height, sf::RenderWindow* renderWindow)
{
	mScreenWidth = width;
	mScreenHeight = height;
	mRenderWindow = renderWindow;

	sf::Font* roboto = new sf::Font();
	roboto->loadFromFile("./assets/fonts/Roboto-Black.ttf");
	fonts["Roboto"] = roboto;
}

Renderer::~Renderer()
{
	std::for_each(fonts.begin(), fonts.end(), [](const auto &pair) {
		delete pair.second;
	});
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

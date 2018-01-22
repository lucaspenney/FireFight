#include "Renderer.h"
#include <iostream>
Renderer::Renderer(int screenWidth, int screenHeight, int viewWidth, int viewHeight, sf::RenderWindow* renderWindow)
{
	mScreenWidth = screenWidth;
	mScreenHeight = screenHeight;
	mViewWidth = viewWidth;
	mViewHeight = viewHeight;
	mRenderWindow = renderWindow;
	mActiveView = sf::View();
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

void Renderer::setViewPosition(float x, float y) {
	mActiveView.setCenter(x,y);
	mRenderWindow->setView(mActiveView);
}

void Renderer::setWindowSize(int width, int height) {
	float xDiff = (float)mViewWidth / (float)width;
	float yDiff = (float)mViewWidth / (float)height;

	float xDiff2 = (float)width / (float)mScreenWidth;
	mActiveView = sf::View();
	mActiveView.setSize(width,height);
	mScreenWidth = width;
	mScreenHeight = height
	mActiveView.zoom(xDiff);
	mRenderWindow->setView(mActiveView);
}

void Renderer::setView(sf::View view) {
	mActiveView = view;
	view.setSize(mScreenWidth, mScreenHeight);
	mRenderWindow->setView(view);
}

sf::View Renderer::getView() {
	return mActiveView;
}

sf::RenderWindow* Renderer::getWindow() {
	return mRenderWindow;
}

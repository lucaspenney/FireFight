#include "Player.h"
#include "Renderer.h"
#include "AssetManager.h"

Player::Player(Renderer* renderer)
{
	mRenderer = renderer;
	sprite.setTexture(AssetManager::textures["fire_extinguisher"]);
	sprite.setScale(sf::Vector2f(4, 4));
	sprite.setPosition(500.0f, 500.f);
	
	view.setCenter(-200, 400);
	//Set the renderer to this players view
	mRenderer->getWindow()->setView(view);
}


Player::~Player()
{
	
}


void Player::render(Renderer* renderer) {
	renderer->drawSprite(sprite, x, y);
}

void Player::update() {
	x += 1;
	y += 1;
}
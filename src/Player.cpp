#include "Player.h"
#include "Renderer.h"
#include "AssetManager.h"

Player::Player()
{
	sprite.setTexture(AssetManager::textures["fire_extinguisher"]);
	sprite.setScale(sf::Vector2f(4, 4));
	sprite.setPosition(500.0f, 500.f);
}


Player::~Player()
{
	
}


void Player::render(Renderer* renderer) {
	//Update the render view
	view.setCenter(100, 400);
	
	//Set the renderer to this players view
	renderer->getWindow()->setView(view);
	
	//Render the player
	renderer->drawSprite(sprite, x, y);
}

void Player::update() {
	x += 1;
	y += 1;
}
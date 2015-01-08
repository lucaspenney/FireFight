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
	view.setCenter(0, 0);
	
	//Set the renderer to this players view
	renderer->getWindow()->setView(view);
	
	//Render the player
	renderer->drawSprite(sprite, x, y);
}

void Player::update() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		x -= 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		x += 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		y -= 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		y += 2;
	}
}
#include "Player.h"
#include "Renderer.h"
#include "AssetManager.h"
#include "Game.h"
#include "Level.h"

Player::Player()
{
	x = 150;
	y = 100;
	sprite.setTexture(AssetManager::textures["player"]);

	animatedSprite = new AnimatedSprite(&sprite, 3, 4, 27, 47);
	boundingBox = new BoundingBox(x, y, 23, 25);

}


Player::~Player()
{
}


void Player::render(Renderer* renderer) {
	renderer->setViewPosition(x,y);

	animatedSprite->tick();

	//Render the player
	renderer->drawSprite(*animatedSprite->sprite, x, y);
}

void Player::update(Game* game) {
	boundingBox->setPosition(x, y+20);
	int xMove = 0;
	int yMove = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		xMove -= 2;
		animatedSprite->setAnimationType(4);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		xMove += 2;
		animatedSprite->setAnimationType(2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		yMove -= 2;
		animatedSprite->setAnimationType(1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		yMove += 2;
		animatedSprite->setAnimationType(3);
	}


	for (std::vector<Tile*>::iterator it = game->level->tiles.begin(); it != game->level->tiles.end(); ++it) {
		Tile* tile = *it;
		if (!tile->solid) continue;
		if (boundingBox->wouldCollide(tile->boundingBox, xMove, 0)) {
			xMove = 0;
		}
		if (boundingBox->wouldCollide(tile->boundingBox, 0, yMove)) {
			yMove = 0;
		}
	}
	if (xMove == 0 && yMove == 0) {
		animatedSprite->setAnimationFrame(1);
	}
	x += xMove;
	y += yMove;
}

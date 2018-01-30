#pragma once
#include "Entity.h"
#include "BoundingBox.h"
#include "AnimatedSprite.h"

class Player : public Entity {
public:
	Player();
	~Player();
	sf::Sprite sprite;
	AnimatedSprite* animatedSprite;
	BoundingBox boundingBox = BoundingBox(0,0,0,0);
	virtual void render(Renderer* renderer);
	virtual void update(Game* game);

	private:

};

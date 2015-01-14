#pragma once
#include <SFML/Graphics.hpp>
class AnimatedSprite {
public:
	AnimatedSprite(sf::Sprite* sprite, int frames, int types, int frameWidth, int frameHeight);
	~AnimatedSprite();
	sf::Sprite* sprite;
	void tick();
	void setSingleMode(bool mode);
private:
	int mFrameWidth;
	int mFrameHeight;
	int mFrames;
	int mTypes;
	unsigned long lastTick;
	bool mSingleAnimMode = false;
	sf::Vector2u currentFrame;
};
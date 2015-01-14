#pragma once
#include <SFML/Graphics.hpp>
class AnimatedSprite {
public:
	AnimatedSprite(sf::Sprite* sprite, int frames, int types, int frameWidth, int frameHeight);
	~AnimatedSprite();
	sf::Sprite* sprite;
	void tick();
	void setSingleMode(bool mode);
	void setAnimationType(int type);
	void setAnimationFrame(int frame);
	void setAnimating(bool animating);
private:
	int mFrameWidth;
	int mFrameHeight;
	int mFrames;
	int mTypes;
	bool mAnimating;
	unsigned long lastTick;
	bool mSingleAnimMode = false;
	sf::Vector2u currentFrame;
};
#include "AnimatedSprite.h"

#include <chrono>
AnimatedSprite::AnimatedSprite(sf::Sprite* sprite, int frames, int types, int frameWidth, int frameHeight)
	:sprite(sprite), mFrames(frames), mTypes(types), mFrameWidth(frameWidth), mFrameHeight(frameHeight)
{
	sf::Vector2u textureSize = sprite->getTexture()->getSize();
	lastTick = 0;
}

AnimatedSprite::~AnimatedSprite() {

}

void AnimatedSprite::tick() {
	unsigned int now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	if (now > lastTick + 122) {
		lastTick = now;
		currentFrame.x++;
		currentFrame.y = 2;
		if (mSingleAnimMode) {
			if (currentFrame.x >= mFrames) {
				currentFrame.y++;
				currentFrame.x = 0;
				if (currentFrame.y >= mTypes) {
					currentFrame.x = 0;
					currentFrame.y = 0;
				}
			}
		}
		else {
			if (currentFrame.x >= mFrames) currentFrame.x = 0;
		}

		sprite->setTextureRect(sf::IntRect(mFrameWidth * currentFrame.x, mFrameHeight * currentFrame.y, mFrameWidth, mFrameHeight));
	}
}

void AnimatedSprite::setSingleMode(bool mode) {
	mSingleAnimMode = mode;
}
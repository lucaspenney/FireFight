#include "BoundingBox.h"

BoundingBox::BoundingBox(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

BoundingBox::~BoundingBox() {

}

bool BoundingBox::isColliding(BoundingBox* other) {
	if (x + width > other->x && x + width < other->x + other->width) {
		if (y + height > other->y && y + height < other->y + other->height) {
			return true;
		}
	}
	return false;
}

bool BoundingBox::wouldCollide(BoundingBox* other, float xVel, float yVel) {
	if (x + width + xVel > other->x && x + xVel < other->x + other->width) {
		if (y + height + yVel > other->y &&  y + yVel < other->y + other->height) {
			return true;
		}
	}
	return false;
}

void BoundingBox::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void BoundingBox::setSize(int width, int height) {
	this->width = width;
	this->height = height;
}
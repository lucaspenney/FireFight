#pragma once
class BoundingBox {
public:
	BoundingBox(int x, int y, int width, int height);
	~BoundingBox();
	int x, y, width, height;
	bool isColliding(BoundingBox* other);
	bool BoundingBox::wouldCollide(BoundingBox* other, float xVel, float yVel);
	void setPosition(int x, int y);
	void setSize(int width, int height);
};
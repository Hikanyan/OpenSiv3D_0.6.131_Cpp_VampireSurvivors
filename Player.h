#pragma once
#include "Vector2.h"
#include "IGameObject.h"

class Player : public IGameObject
{
private:
	int speed_;
	const Texture emoji{ U"🦖"_emoji };

public:
	Player(int x, int y, int speed);

	void Update() override;
	void Draw() override;

	int GetX() const { return position_.getX(); }
	int GetY() const { return position_.getY(); }
	int get_speed() const { return speed_; }
};

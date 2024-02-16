#include "stdafx.h"
#include "Player.h"

Player::Player(int x, int y, int speed)
{
	position_.setX(x);
	position_.setY(y);
	speed_ = speed;
}

void Player::Draw()
{
	emoji_.scaled(0.5).draw(position_.getX(), position_.getY());
}


void Player::Update()
{
	if (KeyA.pressed()) position_.setX(position_.getX() - speed_);
	if (KeyD.pressed()) position_.setX(position_.getX() + speed_);
	if (KeyW.pressed()) position_.setY(position_.getY() - speed_);
	if (KeyS.pressed()) position_.setY(position_.getY() + speed_);

	if (position_.getX() < 0) position_.setX(0);
	if (position_.getX() > 800 - 20) position_.setX(800 - 20);
	if (position_.getY() < 0) position_.setY(0);
	if (position_.getY() > 600 - 20) position_.setY(600 - 20);

	(position_ += Vector2(speed_, speed_)).Normalize();
}

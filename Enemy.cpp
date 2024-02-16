#include "Enemy.h"

Enemy::Enemy(const int x, const int y, const int speed)
{
	position_.setX(x);
	position_.setY(y);
	speed_ = speed;
}

void Enemy::Update()
{
	if (position_.getX() < 20 || position_.getX() > 0) speed_ *= -1;
	if (position_.getY() < 20 || position_.getY() > 0) speed_ *= -1;
	(position_ += Vector2(speed_, speed_)).Normalize();
}

void Enemy::Draw()
{
	emoji_.scaled(0.5).draw(position_.getX(), position_.getY());
}

#pragma once
#include "IGameObject.h"
#include "Transform2D.h"

class Entity : public IGameObject
{
protected:
	int health;
	int damage;
	int move_speed;
	float gravity_volume;
public:
	Entity() {}
	Transform2D transform;
};

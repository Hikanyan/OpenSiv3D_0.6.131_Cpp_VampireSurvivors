#pragma once
#include "Vector2.h"


class IGameObject
{
protected:
	Vector2 position_;
public:
	virtual ~IGameObject() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;

};


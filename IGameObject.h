#pragma once

class IGameObject
{
public:
	virtual ~IGameObject() = default;
	virtual void Update() = 0;
	virtual void Draw() = 0;
};


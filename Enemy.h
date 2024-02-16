#pragma once
#include "IGameObject.h"
class Enemy : public IGameObject
{
private:
	int speed_;
	const Texture emoji_{ U"😎"_emoji };
public:
	Enemy(int x, int y, int speed);
	void Update() override;
	void Draw() override;
};


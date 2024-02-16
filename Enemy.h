#pragma once
#include "Entity.h"
class Enemy : public Entity
{
	const Texture emoji{ U"👿"_emoji };
public:
	Enemy();
	~Enemy();

	void Update() override;
	void Draw() override;
	void ChasePlayer(const Vector2& playerPosition);
};


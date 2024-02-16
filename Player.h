#pragma once
#include "Entity.h"
#include "Transform2D.h"

class Player : public Entity
{
	// 絵文字からテクスチャを作成する | Create a texture from an emoji
	const Texture emoji{ U"🦖"_emoji };

public:
	Player();
	~Player();

	void Update() override;
	void Draw() override;

};


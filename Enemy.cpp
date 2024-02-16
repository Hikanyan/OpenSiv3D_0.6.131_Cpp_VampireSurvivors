#include "stdafx.h"
#include "Enemy.h"

Enemy::Enemy()
{
	transform.position = Vector2(0, 0);
	transform.rotation = Vector2(0, 0);
	transform.scale = Vector2(1, 1);
	health = 100;
	damage = 10;
	move_speed = 5;
	gravity_volume = 9.8f;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	// エネミーの描画処理
	emoji.draw(transform.position.x, transform.position.y);
}

void Enemy::ChasePlayer(const Vector2& playerPosition)
{
	// プレイヤーの位置に向かって少しずつ移動する
	Vector2 direction = playerPosition - transform.position;
	direction.Normalize(); // 方向ベクトルを正規化
	transform.position += direction * move_speed; // 正規化された方向ベクトルにスピードを掛ける
}

#include "stdafx.h"
#include "Player.h"

Player::Player()
{
	transform.position = Vector2(800 / 2, 600 / 2);
	transform.rotation = Vector2(0, 0);
	transform.scale = Vector2(1, 1);
	health = 100;
	damage = 10;
	move_speed = 5;
	gravity_volume = 9.8f;
}

Player::~Player()
{
}

void Player::Update()
{
	if (health <= 0)
	{
		// Destroy(); // プレイヤーの破壊またはゲームオーバー処理
		return;
	}

	Vector2 movement(0, 0); // 移動量の初期化

	// キー入力に基づく移動量の計算
	if (KeyLeft.pressed() || KeyA.pressed()) movement.x -= 1;
	if (KeyRight.pressed() || KeyD.pressed()) movement.x += 1;
	if (KeyUp.pressed() || KeyW.pressed()) movement.y -= 1; // Y軸が上向きに正である場合は、値を減算
	if (KeyDown.pressed() || KeyS.pressed()) movement.y += 1;

	// 移動量が0でない場合にのみ正規化を行う
	if (movement.x != 0 || movement.y != 0) {
		movement.Normalize(); // 移動ベクトルを正規化
		movement *= move_speed; // 正規化された移動ベクトルに移動速度を適用
	}

	// 世界の壁
	if (transform.position.x < 0) transform.position.x = 0;
	if (transform.position.x > 800) transform.position.x = 800;
	if (transform.position.y < 0) transform.position.y = 0;
	if (transform.position.y > 600) transform.position.y = 600;

	// 正規化され、スケールされた移動量を現在位置に加算
	transform.position += movement;
}


void Player::Draw()
{
	// プレイヤーを描く | Draw the player
	emoji.scaled(0.75).drawAt(transform.position.x, transform.position.y);

}

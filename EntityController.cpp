#include "stdafx.h"
#include "EntityController.h"
#include "Player.h"
#include "Enemy.h"

EntityController::EntityController()
{
	player = new Player();
	entities_.push_back(std::unique_ptr<Player>(player));
	lastSpawnTime = std::chrono::steady_clock::now();
}

EntityController::~EntityController()
{
	entities_.clear();
}
void EntityController::Update() {
	auto now = std::chrono::steady_clock::now();
	if (now - lastSpawnTime > spawnInterval) {
		SpawnEnemy();
		lastSpawnTime = now; // 最後のスポーン時刻を更新
	}

	for (auto& entity : entities_) {
		entity->Update();
	}
	ChasePlayer();
}

void EntityController::Draw()
{
	for (auto& entity : entities_)
	{
		entity->Draw();
	}
}

void EntityController::RandomPosition(Entity* entity)
{
	// 画面外のランダムな位置に配置する→Playerに向かってくる

	// std::random_deviceをシードとして使用
	std::random_device rd;
	std::mt19937 gen(rd());

	// xとy座標のための乱数生成器を定義 +10で画面外から出る
	std::uniform_int_distribution<> disX(0 - 10, 800 + 10);
	std::uniform_int_distribution<> disY(0 - 10, 600 + 10);

	// 画面外のランダムな位置に配置
	entity->transform.position.x = disX(gen);
	entity->transform.position.y = disY(gen);

}

void EntityController::ChasePlayer() {
	Vector2 playerPosition = player->transform.position; // プレイヤーの位置を取得
	for (auto& entity : entities_) {
		Enemy* enemy = dynamic_cast<Enemy*>(entity.get()); // dynamic_castを使用してEnemyにキャスト
		if (enemy) {
			enemy->ChasePlayer(playerPosition); // エネミーがプレイヤーを追いかける
		}
	}
}




void EntityController::SpawnEnemy() {
	auto enemy = std::make_unique<Enemy>();
	// 必要に応じてエネミーの初期位置を設定
	RandomPosition(enemy.get());
	entities_.push_back(std::move(enemy));
}

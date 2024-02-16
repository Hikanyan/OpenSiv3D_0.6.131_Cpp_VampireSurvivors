#pragma once
#include "Entity.h"
#include "Singleton.h"
#include "Player.h"

class EntityController : public Singleton<EntityController>
{
	std::vector<std::unique_ptr<Entity>> entities_;
	Player* player;

	std::chrono::steady_clock::time_point lastSpawnTime; // 最後にエネミーを生成した時刻
	std::chrono::milliseconds spawnInterval{ 2000 }; // エネミーを生成する間隔（ミリ秒）
public:
	EntityController();
	~EntityController();

	void Update();
	void Draw();
private:
	void RandomPosition(Entity* entity);
	void ChasePlayer();
	void SpawnEnemy();
};


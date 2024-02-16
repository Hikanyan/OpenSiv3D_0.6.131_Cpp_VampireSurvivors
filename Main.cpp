# include <Siv3D.hpp>

#include "Player.h"
#include "Enemy.h"

void Main()
{

	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });
	Player player(400, 300, 10);
	Enemy enemy(200, 200, 5);

	while (System::Update())
	{
		player.Update();
		enemy.Update();
		player.Draw();
		enemy.Draw();
	}
}



//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//

#pragma once
#include <cstddef>

class Enemy {
public:
	Enemy();

	void Update();

private:
	// 状態
	enum class Phase {
		Approach, // 接近
		Shoot,    // 射撃
		Escape,   // 離脱
		Count     // 要素数
	};

	Phase phase_;

	// 各状態の処理
	void Approach();
	void Shoot();
	void Escape();

	// メンバ関数ポインタテーブル
	static void (Enemy::* spFuncTable[static_cast<size_t>(Phase::Count)])();
};

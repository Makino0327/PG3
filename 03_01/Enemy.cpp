#include "Enemy.h"
#include <iostream>

// メンバ関数ポインタテーブルの実体
void (Enemy::* Enemy::spFuncTable[static_cast<size_t>(Enemy::Phase::Count)])() = {
	&Enemy::Approach,
	&Enemy::Shoot,
	&Enemy::Escape
};

Enemy::Enemy()
	: phase_(Phase::Approach) {
}

void Enemy::Update() {
	// 現在の状態の関数を実行
	(this->*spFuncTable[static_cast<size_t>(phase_)])();
}

void Enemy::Approach() {
	std::cout << "【接近】敵がプレイヤーに近づいている\n";
	phase_ = Phase::Shoot;
}

void Enemy::Shoot() {
	std::cout << "【射撃】敵が攻撃している\n";
	phase_ = Phase::Escape;
}

void Enemy::Escape() {
	std::cout << "【離脱】敵が距離を取る\n";
	phase_ = Phase::Approach;
}

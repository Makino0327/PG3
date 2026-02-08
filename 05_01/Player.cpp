#include "Player.h"

void Player::Init(float x, float y, float speed) {
    posX_ = x;
    posY_ = y;
    speed_ = speed;
}

void Player::MoveLeft() {
    posX_ -= speed_;
}

void Player::MoveRight() {
    posX_ += speed_;
}

void Player::Update() {
    // 今回は特に無し
}

void Player::Draw() const {
    const int size = 50;
    Novice::DrawBox(
        static_cast<int>(posX_ - size * 0.5f),
        static_cast<int>(posY_ - size * 0.5f),
        size, size, 0.0f,
        0xFFFFFFFF, kFillModeSolid
    );
}

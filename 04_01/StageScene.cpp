// StageScene.cpp
#include "StageScene.h"
#include <Novice.h>
#include "InputManager.h"

void StageScene::Init() {
    // 元コードの初期化をここに移す
    playerPosX_ = 200.0f;
    playerPosY_ = 200.0f;
    playerSpeed_ = 5.0f;
    playerRadius_ = 20.0f;

    bulletPosX_ = 100.0f;
    bulletPosY_ = 100.0f;
    bulletSpeed_ = 10.0f;
    isBulletShot_ = false;

    enemyPosX_ = 50.0f;
    enemyPosY_ = 20.0f;
    enemyRadius_ = 20.0f;
    enemySpeed_ = 2.0f;
    isEnemyAlive_ = true;
    enemyRespawnTimer_ = 120;

    if (graphHandleExplode_ == -1) {
        graphHandleExplode_ = Novice::LoadTexture("./Resources/explode.png");
    }
}

void StageScene::Update(InputManager& input) {
    //=====================
    // player
    //=====================
    if (input.Press(DIK_W)) { playerPosY_ -= playerSpeed_; }
    if (input.Press(DIK_A)) { playerPosX_ -= playerSpeed_; }
    if (input.Press(DIK_S)) { playerPosY_ += playerSpeed_; }
    if (input.Press(DIK_D)) { playerPosX_ += playerSpeed_; }

    // 画面外に行かない
    if (playerPosY_ <= 20.0f) { playerPosY_ = 1.0f + playerRadius_; }
    if (playerPosX_ <= 20.0f) { playerPosX_ = 1.0f + playerRadius_; }
    if (playerPosY_ >= 700.0f) { playerPosY_ = 719.0f - playerRadius_; }
    if (playerPosX_ >= 1260.0f) { playerPosX_ = 1279.0f - playerRadius_; }

    //=====================
    // enemy
    //=====================
    if (isEnemyAlive_) {
        enemyPosX_ += enemySpeed_;

        if (enemyPosX_ >= 1260.0f || enemyPosX_ <= 20.0f) {
            enemySpeed_ *= -1.0f;
        }
    } else {
        enemyRespawnTimer_--;

        if (enemyRespawnTimer_ <= 0) {
            enemyRespawnTimer_ += 120;
            isEnemyAlive_ = true;
        }
    }

    //=====================
    // bullet
    //=====================
    if (input.Trigger(DIK_SPACE)) {
        if (!isBulletShot_) {
            isBulletShot_ = true;
            bulletPosX_ = playerPosX_;
            bulletPosY_ = playerPosY_;
        }
    }

    if (isBulletShot_) {
        bulletPosY_ -= bulletSpeed_;
        if (bulletPosY_ <= -40.0f) {
            isBulletShot_ = false;
        }
    }

    //=====================
    // hit
    //=====================
    if (isEnemyAlive_ && isBulletShot_) {
        float dx = bulletPosX_ - enemyPosX_;
        float dy = bulletPosY_ - enemyPosY_;
        float r = playerRadius_ + enemyRadius_;

        if (r * r >= dx * dx + dy * dy) {
            isEnemyAlive_ = false;
            isBulletShot_ = false;

            // ★敵を倒したらクリアへ（課題条件の「敵倒す＆シーン切替」）
            sceneNo_ = CLEAR;
        }
    }
}

void StageScene::Draw() {
    // player
    Novice::DrawBox(
        static_cast<int>(playerPosX_) - static_cast<int>(playerRadius_),
        static_cast<int>(playerPosY_) - static_cast<int>(playerRadius_),
        static_cast<int>(playerRadius_) * 2,
        static_cast<int>(playerRadius_) * 2,
        0.0f, WHITE, kFillModeSolid
    );

    // bullet
    if (isBulletShot_) {
        Novice::DrawTriangle(
            static_cast<int>(bulletPosX_) - static_cast<int>(playerRadius_) / 2,
            static_cast<int>(bulletPosY_),
            static_cast<int>(bulletPosX_) + static_cast<int>(playerRadius_) / 2,
            static_cast<int>(bulletPosY_),
            static_cast<int>(bulletPosX_),
            static_cast<int>(bulletPosY_) - static_cast<int>(playerRadius_),
            WHITE, kFillModeSolid
        );
    }

    // enemy / explode
    if (isEnemyAlive_) {
        Novice::DrawEllipse(
            static_cast<int>(enemyPosX_),
            static_cast<int>(enemyPosY_),
            static_cast<int>(enemyRadius_),
            static_cast<int>(enemyRadius_),
            0.0f, WHITE, kFillModeSolid
        );
    } else {
        if (enemyRespawnTimer_ > 90) {
            Novice::DrawSprite(
                static_cast<int>(enemyPosX_),
                static_cast<int>(enemyPosY_),
                graphHandleExplode_,
                1, 1, 0.0f, 0xFFFFFFFF
            );
        }
    }
}

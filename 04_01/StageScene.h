// StageScene.h
#pragma once
#include "IScene.h"

class StageScene : public IScene {
public:
    StageScene() = default;

    void Init() override;
    void Update(class InputManager& input) override;
    void Draw() override;

private:
    // player
    float playerPosX_ = 200.0f;
    float playerPosY_ = 200.0f;
    float playerSpeed_ = 5.0f;
    float playerRadius_ = 20.0f;

    // bullet
    float bulletPosX_ = 100.0f;
    float bulletPosY_ = 100.0f;
    float bulletSpeed_ = 10.0f;
    bool isBulletShot_ = false;

    // enemy
    float enemyPosX_ = 50.0f;
    float enemyPosY_ = 20.0f;
    float enemyRadius_ = 20.0f;
    float enemySpeed_ = 2.0f;
    bool isEnemyAlive_ = true;
    int enemyRespawnTimer_ = 120;

    int graphHandleExplode_ = -1;
};

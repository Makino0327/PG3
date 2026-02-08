#pragma once
#include <Novice.h>

class Player {
public:
    void Init(float x, float y, float speed);
    void MoveLeft();
    void MoveRight();
    void Update();
    void Draw() const;

private:
    float posX_ = 0.0f;
    float posY_ = 0.0f;
    float speed_ = 5.0f;
};

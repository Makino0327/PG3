#pragma once

#include "Player.h"
#include "InputHandler.h"
#include "Command.h"

class StageScene {
public:
    void Init();
    void Update(const char keys[256]);
    void Draw() const;

private:
    Player player_;
    InputHandler inputHandler_;

    // コマンド実体は StageScene が所有（newしない）
    MoveLeftCommand moveLeft_;
    MoveRightCommand moveRight_;
};

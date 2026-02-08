#include "StageScene.h"

void StageScene::Init() {
    player_.Init(640.0f, 360.0f, 6.0f);

    inputHandler_.AssignMoveLeftCommandToKeyA(&moveLeft_);
    inputHandler_.AssignMoveRightCommandToKeyD(&moveRight_);
}

void StageScene::Update(const char keys[256]) {
    ICommand* command = inputHandler_.HandleInput(keys);
    if (command) {
        command->Exec(player_);
    }
    player_.Update();
}

void StageScene::Draw() const {
    player_.Draw();
}

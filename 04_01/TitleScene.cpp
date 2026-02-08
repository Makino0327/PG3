// TitleScene.cpp
#include "TitleScene.h"
#include <Novice.h>
#include "InputManager.h"

void TitleScene::Init() {
    // 何か初期化が必要ならここ
}

void TitleScene::Update(InputManager& input) {
    // SPACEでゲームへ
    if (input.Trigger(DIK_SPACE)) {
        sceneNo_ = STAGE;
    }
}

void TitleScene::Draw() {
    Novice::ScreenPrintf(520, 300, "TITLE");
}

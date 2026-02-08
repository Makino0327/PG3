// ClearScene.cpp
#include "ClearScene.h"
#include <Novice.h>
#include "InputManager.h"

void ClearScene::Init() {
    // クリア突入時の初期化が必要ならここ
}

void ClearScene::Update(InputManager& input) {
    // SPACEでタイトルに戻る（またはSTAGEへリトライでもOK）
    if (input.Trigger(DIK_SPACE)) {
        sceneNo_ = TITLE;
    }
}

void ClearScene::Draw() {
    Novice::ScreenPrintf(520, 300, "CLEAR!");
}

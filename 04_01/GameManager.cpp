#include "GameManager.h"
#include <Novice.h>

#include "InputManager.h"
#include "TitleScene.h"
#include "StageScene.h"
#include "ClearScene.h"

GameManager::GameManager() {
    sceneArr_[TITLE] = std::make_unique<TitleScene>();
    sceneArr_[STAGE] = std::make_unique<StageScene>();
    sceneArr_[CLEAR] = std::make_unique<ClearScene>();

    currentSceneNo_ = TITLE;
    prevSceneNo_ = TITLE;

    sceneArr_[currentSceneNo_]->Init();
}

int GameManager::Run() {
    InputManager input;

    while (Novice::ProcessMessage() == 0) {
        Novice::BeginFrame();

        input.Update();

        // シーン番号の監視
        prevSceneNo_ = currentSceneNo_;
        currentSceneNo_ = sceneArr_[currentSceneNo_]->GetScene();

        // 切り替わったらInit
        if (prevSceneNo_ != currentSceneNo_) {
            sceneArr_[currentSceneNo_]->Init();
        }

        // 更新・描画
        sceneArr_[currentSceneNo_]->Update(input);
        sceneArr_[currentSceneNo_]->Draw();

        Novice::EndFrame();

        // ESCで終了（課題サンプルに合わせる）
        if (input.Trigger(DIK_ESCAPE)) {
            break;
        }
    }

    return 0;
}

#include "StageScene.h"
#include "StageSceneInputHandler.h"
#include "Selector.h"
#include "IStageSceneCommand.h"

StageScene::StageScene() = default;

StageScene::~StageScene() {
    ClearAllHistory();
    delete selector_;
    delete input_;
}

void StageScene::Init() {
    input_ = new StageSceneInputHandler();

    selector_ = new Selector();
    selector_->Init(32, 18);

    history_.clear();
    itr_ = history_.begin();
}

void StageScene::ClearAllHistory() {
    for (auto* c : history_) delete c;
    history_.clear();
    itr_ = history_.begin();
}

void StageScene::ClearHistoryFromIteratorToEnd() {
    // itr_ 以降（未来）を削除
    auto it = itr_;
    while (it != history_.end()) {
        delete* it;
        it = history_.erase(it);
    }
}

void StageScene::ExecAndStore(IStageSceneCommand* cmd) {
    if (!cmd) return;

    // Undoで戻った位置から新操作したら未来を消す
    if (itr_ != history_.end()) {
        ClearHistoryFromIteratorToEnd();
    }

    cmd->Exec();

    history_.push_back(cmd);
    itr_ = history_.end(); // 常に最後を指す
}

void StageScene::UndoReplay() {
    if (history_.empty()) return;
    if (itr_ == history_.begin()) return;

    // 1つ戻す
    --itr_;

    // 最初から再生のため初期化に戻す
    selector_->Reset();

    // begin から itr_ まで Exec
    for (auto it = history_.begin(); it != itr_; ++it) {
        (*it)->Exec();
    }
}

void StageScene::Update() {
    input_->UpdateKeyState();

    // Selector Mode では Undo 不可（仕様）
    if (selector_->GetSelectMode() == UNIT) {
        bool nowUndo = input_->CheckUndoStatus();

        // 押しっぱなしで連打にならないようにラッチ
        if (nowUndo && !undoLatch_) {
            UndoReplay();
            undoLatch_ = true;
        }
        if (!nowUndo) {
            undoLatch_ = false;
        }
    } else {
        undoLatch_ = false;
    }

    // コマンド生成
    command_ = nullptr;

    if (selector_->GetSelectMode() == SELECTOR) {
        command_ = input_->SelectorHandleInput(selector_);
    } else {
        command_ = input_->UnitHandleInput(selector_->GetSelectedUnitAddress());
    }

    // 実行と履歴
    ExecAndStore(command_);
    command_ = nullptr;

    selector_->Update();
}

void StageScene::Draw() {
    // ここは Novice の描画に合わせて差し替え
    selector_->Draw();
}

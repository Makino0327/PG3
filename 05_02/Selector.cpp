#include "Selector.h"
#include "Unit.h"
#include <Novice.h>

namespace {
    constexpr int kCell = 32;      // 1マスの大きさ
    constexpr int kOriginX = 40;   // 左上オフセット（見やすく）
    constexpr int kOriginY = 40;

    inline int ToScreenX(int mapX) { return kOriginX + mapX * kCell; }
    inline int ToScreenY(int mapY) { return kOriginY + mapY * kCell; }
}

void Selector::Draw() const {

    // ===== グリッド =====
    for (int y = 0; y <= mapH_; ++y) {
        int sy = kOriginY + y * kCell;
        Novice::DrawLine(
            kOriginX, sy,
            kOriginX + mapW_ * kCell, sy,
            0xFFFFFF66
        );
    }
    for (int x = 0; x <= mapW_; ++x) {
        int sx = kOriginX + x * kCell;
        Novice::DrawLine(
            sx, kOriginY,
            sx, kOriginY + mapH_ * kCell,
            0xFFFFFF66
        );
    }

    // ===== ユニット（白 / 選択中は黄）=====
    for (const auto& u : units_) {
        int x = ToScreenX(u.GetX());
        int y = ToScreenY(u.GetY());

        unsigned int col = u.IsSelected() ? 0xFFFF00FF : 0xFFFFFFFF;

        Novice::DrawBox(
            x + 4, y + 4,
            kCell - 8, kCell - 8,
            0.0f,
            col,
            kFillModeSolid
        );
    }

    // ===== セレクタ（赤枠）=====
    {
        int x = ToScreenX(mapX_);
        int y = ToScreenY(mapY_);

        Novice::DrawBox(
            x, y,
            kCell, kCell,
            0.0f,
            0xFF0000FF,
            kFillModeWireFrame
        );
    }

    // ===== 文字（状態）=====
    Novice::ScreenPrintf(10, 10, "Mode: %s", (selectMode_ == SELECTOR) ? "SELECTOR" : "UNIT");
    Novice::ScreenPrintf(10, 30, "Move: WASD/Arrow  Select: SPACE  Undo: Ctrl+Z (UNIT only)");
    if (selectMode_ == SELECTOR) {
        Novice::ScreenPrintf(10, 50, "In Selector Mode, you cannot use the 'Undo' action.");
    }
}

void Selector::Init(int mapW, int mapH) {
    mapW_ = mapW;
    mapH_ = mapH;

    mapX_ = 1;
    mapY_ = 1;
    selectMode_ = SELECTOR;

    units_.clear();
    units_.resize(5);

    // サンプル配置（適当に5体）
    units_[0].Init(0, 6, 2);
    units_[1].Init(1, 28, 4);
    units_[2].Init(2, 13, 8);
    units_[3].Init(3, 16, 7);
    units_[4].Init(4, 22, 7);

    selectedUnit_ = nullptr;
}

void Selector::Reset() {
    // 初期化状態に戻す（Undoの“最初から再生”用）
    Init(mapW_, mapH_);
}

void Selector::Update() {
    for (auto& u : units_) {
        u.Update();
    }
}


void Selector::Move(int dx, int dy) {
    int nx = mapX_ + dx;
    int ny = mapY_ + dy;

    if (nx < 0) nx = 0;
    if (ny < 0) ny = 0;
    if (nx >= mapW_) nx = mapW_ - 1;
    if (ny >= mapH_) ny = mapH_ - 1;

    mapX_ = nx;
    mapY_ = ny;
}

void Selector::SelectUnit() {
    // 今いるマスにいるユニットを探す
    Unit* hit = nullptr;
    for (auto& u : units_) {
        if (u.GetX() == mapX_ && u.GetY() == mapY_) {
            hit = &u;
            break;
        }
    }

    // 見つからなかったら何もしない（サンプル仕様）
    if (!hit) return;

    // 既に同じのを選んでたら解除して SELECTOR に戻す
    if (selectedUnit_ == hit && selectMode_ == UNIT) {
        selectedUnit_->SetSelected(false);
        selectedUnit_ = nullptr;
        selectMode_ = SELECTOR;
        return;
    }

    // 別のを選ぶ
    if (selectedUnit_) selectedUnit_->SetSelected(false);

    selectedUnit_ = hit;
    selectedUnit_->SetSelected(true);
    selectMode_ = UNIT;
}

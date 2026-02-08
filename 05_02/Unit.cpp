#include "Unit.h"
#include "Selector.h"

void Unit::Init(int id, int x, int y) {
    id_ = id;
    mapX_ = x;
    mapY_ = y;
    isSelected_ = false;
}

void Unit::Update() {
    // 今回は特に無し
}

void Unit::Draw() const {
    // 描画は環境に合わせて差し替え
}

void Unit::Move(int dx, int dy) {
    mapX_ += dx;
    mapY_ += dy;
}

void Unit::MoveEnd(Selector* selector) {
    (void)selector;
    // 必要なら「移動確定」処理をここに
}

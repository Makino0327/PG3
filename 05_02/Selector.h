#pragma once
#include <vector>
#include "Unit.h"   // ★これを追加（class Unit; をやめる）

enum SelectMode {
    SELECTOR = 0,
    UNIT = 1,
};

class Selector {
private:
    int mapX_ = 0;
    int mapY_ = 0;

    int mapW_ = 32;
    int mapH_ = 18;

    SelectMode selectMode_ = SELECTOR;

    std::vector<Unit> units_;   // ★ Unit は完全型になったのでOK
    Unit* selectedUnit_ = nullptr;

public:
    Selector() = default;

    void Init(int mapW, int mapH);
    void Update();
    void Draw() const;

    void Reset();

    void Move(int dx, int dy);
    void SelectUnit();

    SelectMode GetSelectMode() const { return selectMode_; }
    void SetSelectMode(SelectMode m) { selectMode_ = m; }

    Unit* GetSelectedUnitAddress() { return selectedUnit_; }

    const std::vector<Unit>& GetUnits() const { return units_; }
    std::vector<Unit>& GetUnits() { return units_; }

    int GetX() const { return mapX_; }
    int GetY() const { return mapY_; }

    int GetMapW() const { return mapW_; }
    int GetMapH() const { return mapH_; }
};

#pragma once

class Selector;

class Unit {
private:
    int mapX_ = 0;
    int mapY_ = 0;
    int id_ = 0;
    bool isSelected_ = false;

public:
    Unit() = default;

    void Init(int id, int x, int y);
    void Update();
    void Draw() const;

    void Move(int dx, int dy);
    void MoveEnd(Selector* selector);

    int GetX() const { return mapX_; }
    int GetY() const { return mapY_; }
    int GetId() const { return id_; }

    bool IsSelected() const { return isSelected_; }
    void SetSelected(bool v) { isSelected_ = v; }
};

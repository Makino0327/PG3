#pragma once

class IShape {
public:
    virtual ~IShape() {}

    virtual void Size() = 0; // 面積を求める
    virtual void Draw() = 0; // 表示する
};

#pragma once
#include "IShape.h"

class Rectangle : public IShape {
public:
    Rectangle(double w, double h);

    void Size() override;
    void Draw() override;

private:
    double width_;
    double height_;
    double area_;
};

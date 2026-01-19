#pragma once
#include "IShape.h"

class Circle : public IShape {
public:
    Circle(double r);

    void Size() override;
    void Draw() override;

private:
    double radius_;
    double area_;
};

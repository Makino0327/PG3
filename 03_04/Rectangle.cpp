#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double w, double h)
    : width_(w), height_(h), area_(0) {
}

void Rectangle::Size() {
    area_ = width_ * height_;
}

void Rectangle::Draw() {
    std::cout << "Rectangle Area = " << area_ << std::endl;
}

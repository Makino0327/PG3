#include "Circle.h"
#include <iostream>

Circle::Circle(double r)
    : radius_(r), area_(0) {
}

void Circle::Size() {
    area_ = 3.141592 * radius_ * radius_;
}

void Circle::Draw() {
    std::cout << "Circle Area = " << area_ << std::endl;
}

#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    void Run() override {
        std::cout << "車がエンジンで走る" << std::endl;
    }
};

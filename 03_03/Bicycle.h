#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    void Run() override {
        std::cout << "自転車がペダルで走る" << std::endl;
    }
};

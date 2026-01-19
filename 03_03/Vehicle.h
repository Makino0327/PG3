#pragma once
#include <iostream>

class Vehicle {
public:
    virtual ~Vehicle() {}

    virtual void Run() {
        std::cout << "乗り物が走る" << std::endl;
    }
};

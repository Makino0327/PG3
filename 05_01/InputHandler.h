#pragma once
#include <dinput.h>

class ICommand;

class InputHandler {
public:
    void AssignMoveLeftCommandToKeyA(ICommand* command);
    void AssignMoveRightCommandToKeyD(ICommand* command);

    ICommand* HandleInput(const char keys[256]) const;

private:
    ICommand* pressKeyA_ = nullptr;
    ICommand* pressKeyD_ = nullptr;
};

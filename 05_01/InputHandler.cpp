#include "InputHandler.h"
#include "Command.h"

void InputHandler::AssignMoveLeftCommandToKeyA(ICommand* command) {
    pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommandToKeyD(ICommand* command) {
    pressKeyD_ = command;
}

ICommand* InputHandler::HandleInput(const char keys[256]) const {
    if (keys[DIK_A]) { return pressKeyA_; }
    if (keys[DIK_D]) { return pressKeyD_; }
    return nullptr;
}

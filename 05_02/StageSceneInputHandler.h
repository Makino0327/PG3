#pragma once
#include "IStageSceneCommand.h"

class Selector;
class Unit;

class StageSceneInputHandler {
private:
    char keys_[256]{};
    char preKeys_[256]{};

public:
    StageSceneInputHandler() = default;

    void UpdateKeyState();

    IStageSceneCommand* SelectorHandleInput(Selector* selector);
    IStageSceneCommand* UnitHandleInput(Unit* unit);

    bool CheckUndoStatus() const;
};

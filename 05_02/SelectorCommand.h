#pragma once
#include "IStageSceneCommand.h"

class Selector;

class SelectorMoveCommand : public IStageSceneCommand {
public:
    SelectorMoveCommand(Selector* selector, int dx, int dy);
    void Exec() override;

private:
    Selector* selector_ = nullptr;
    int dx_ = 0;
    int dy_ = 0;
};

class SelectUnitCommand : public IStageSceneCommand {
public:
    explicit SelectUnitCommand(Selector* selector);
    void Exec() override;

private:
    Selector* selector_ = nullptr;
};

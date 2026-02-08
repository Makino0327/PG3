#pragma once
#include "IStageSceneCommand.h"

class Unit;
class Selector;

class UnitMoveCommand : public IStageSceneCommand {
public:
    UnitMoveCommand(Unit* unit, int dx, int dy);
    void Exec() override;

private:
    Unit* unit_ = nullptr;
    int dx_ = 0;
    int dy_ = 0;
};

class UnitMoveEndCommand : public IStageSceneCommand {
public:
    UnitMoveEndCommand(Unit* unit, Selector* selector);
    void Exec() override;

private:
    Unit* unit_ = nullptr;
    Selector* selector_ = nullptr;
};

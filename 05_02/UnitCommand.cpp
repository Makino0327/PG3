#include "UnitCommand.h"
#include "Unit.h"
#include "Selector.h"

UnitMoveCommand::UnitMoveCommand(Unit* unit, int dx, int dy)
    : unit_(unit), dx_(dx), dy_(dy) {
}

void UnitMoveCommand::Exec() {
    if (!unit_) return;
    unit_->Move(dx_, dy_);
}

UnitMoveEndCommand::UnitMoveEndCommand(Unit* unit, Selector* selector)
    : unit_(unit), selector_(selector) {
}

void UnitMoveEndCommand::Exec() {
    if (!unit_ || !selector_) return;
    unit_->MoveEnd(selector_);
    selector_->SetSelectMode(SELECTOR);
    unit_->SetSelected(false);
}

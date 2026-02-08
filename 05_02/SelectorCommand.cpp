#include "SelectorCommand.h"
#include "Selector.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, int dx, int dy)
    : selector_(selector), dx_(dx), dy_(dy) {
}

void SelectorMoveCommand::Exec() {
    if (!selector_) return;
    selector_->Move(dx_, dy_);
}

SelectUnitCommand::SelectUnitCommand(Selector* selector)
    : selector_(selector) {
}

void SelectUnitCommand::Exec() {
    if (!selector_) return;
    selector_->SelectUnit();
}

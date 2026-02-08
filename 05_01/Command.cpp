#include "Command.h"
#include "Player.h"

void MoveLeftCommand::Exec(Player& player) {
    player.MoveLeft();
}

void MoveRightCommand::Exec(Player& player) {
    player.MoveRight();
}

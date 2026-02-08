#pragma once

class Player;

class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void Exec(Player& player) = 0;
};

class MoveLeftCommand : public ICommand {
public:
    void Exec(Player& player) override;
};

class MoveRightCommand : public ICommand {
public:
    void Exec(Player& player) override;
};

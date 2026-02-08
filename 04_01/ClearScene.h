// ClearScene.h
#pragma once
#include "IScene.h"

class ClearScene : public IScene {
public:
    void Init() override;
    void Update(class InputManager& input) override;
    void Draw() override;
};

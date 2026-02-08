#pragma once
#include <memory>
#include "IScene.h"

class InputManager;

class GameManager {
public:
    GameManager();
    ~GameManager() = default;

    int Run();

private:
    std::unique_ptr<IScene> sceneArr_[SCENE_COUNT];

    int currentSceneNo_ = TITLE;
    int prevSceneNo_ = TITLE;
};

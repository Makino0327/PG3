#pragma once

enum SCENE {
    TITLE = 0,
    STAGE,
    CLEAR,
    SCENE_COUNT
};

class InputManager;

class IScene {
protected:
    static int sceneNo_; // 次シーン要求（Stateの核）

public:
    virtual ~IScene() = default;

    virtual void Init() = 0;
    virtual void Update(InputManager& input) = 0;
    virtual void Draw() = 0;

    int GetScene() const { return sceneNo_; }
};

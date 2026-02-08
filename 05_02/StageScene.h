#pragma once
#include <list>

class Selector;
class StageSceneInputHandler;
class IStageSceneCommand;

class StageScene {
private:
    StageSceneInputHandler* input_ = nullptr;
    IStageSceneCommand* command_ = nullptr;

    std::list<IStageSceneCommand*> history_;
    std::list<IStageSceneCommand*>::iterator itr_;

    Selector* selector_ = nullptr;

    bool undoLatch_ = false; // Ctrl+Z 長押し対策

public:
    StageScene();
    ~StageScene();

    void Init();
    void Update();
    void Draw();

private:
    void ExecAndStore(IStageSceneCommand* cmd);
    void UndoReplay();
    void ClearHistoryFromIteratorToEnd();
    void ClearAllHistory();
};

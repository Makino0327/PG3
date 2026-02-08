#include "StageSceneInputHandler.h"
#include "Selector.h"
#include "Unit.h"
#include "SelectorCommand.h"
#include "UnitCommand.h"

#ifdef _WIN32
#include <Windows.h>
#endif

// Novice を使う場合はここを差し替え
// 例: Novice::GetHitKeyStateAll(keys_);
static void GetKeyStateAll(char keys[256]) {
#ifdef _WIN32
    for (int i = 0; i < 256; ++i) {
        keys[i] = (GetAsyncKeyState(i) & 0x8000) ? 1 : 0;
    }
#else
    (void)keys;
#endif
}

void StageSceneInputHandler::UpdateKeyState() {
    for (int i = 0; i < 256; ++i) preKeys_[i] = keys_[i];
    GetKeyStateAll(keys_);
}

static bool IsTrigger(const char* keys, const char* pre, int vk) {
    return keys[vk] && !pre[vk];
}

IStageSceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector) {
    if (!selector) return nullptr;

    int dx = 0, dy = 0;

    // WASD or Arrow（右=+x, 下=+y）
    if (IsTrigger(keys_, preKeys_, 'A') || IsTrigger(keys_, preKeys_, VK_LEFT))  dx = -1;
    if (IsTrigger(keys_, preKeys_, 'D') || IsTrigger(keys_, preKeys_, VK_RIGHT)) dx = 1;
    if (IsTrigger(keys_, preKeys_, 'W') || IsTrigger(keys_, preKeys_, VK_UP))    dy = -1;
    if (IsTrigger(keys_, preKeys_, 'S') || IsTrigger(keys_, preKeys_, VK_DOWN))  dy = 1;

    if (dx != 0 || dy != 0) {
        return new SelectorMoveCommand(selector, dx, dy);
    }

    // Space: select unit
    if (IsTrigger(keys_, preKeys_, VK_SPACE)) {
        return new SelectUnitCommand(selector);
    }

    return nullptr;
}

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit) {
    if (!unit) return nullptr;

    int dx = 0, dy = 0;

    if (IsTrigger(keys_, preKeys_, 'A') || IsTrigger(keys_, preKeys_, VK_LEFT))  dx = -1;
    if (IsTrigger(keys_, preKeys_, 'D') || IsTrigger(keys_, preKeys_, VK_RIGHT)) dx = 1;
    if (IsTrigger(keys_, preKeys_, 'W') || IsTrigger(keys_, preKeys_, VK_UP))    dy = -1;
    if (IsTrigger(keys_, preKeys_, 'S') || IsTrigger(keys_, preKeys_, VK_DOWN))  dy = 1;

    if (dx != 0 || dy != 0) {
        return new UnitMoveCommand(unit, dx, dy);
    }

    return nullptr;
}

bool StageSceneInputHandler::CheckUndoStatus() const {
    // Ctrl+Z（押してる間でOK）
    return (keys_[VK_CONTROL] && keys_['Z']);
}

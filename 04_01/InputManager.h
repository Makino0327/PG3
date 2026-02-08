#pragma once
#include <Novice.h>
#include <cstring>

class InputManager {
public:
    void Update() {
        std::memcpy(preKeys_, keys_, 256);
        Novice::GetHitKeyStateAll(keys_);
    }

    bool Press(int dik) const { return keys_[dik] != 0; }
    bool Trigger(int dik) const { return preKeys_[dik] == 0 && keys_[dik] != 0; }

private:
    char keys_[256] = { 0 };
    char preKeys_[256] = { 0 };
};

#include <Novice.h>
#include "GameManager.h"

const char kWindowTitle[] = "LC1C_24_マキノハルト_タイトル";

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    Novice::Initialize(kWindowTitle, 1280, 720);

    GameManager game;
    game.Run(); // Runの中で ProcessMessage / BeginFrame / EndFrame を回す

    Novice::Finalize();
    return 0;
}

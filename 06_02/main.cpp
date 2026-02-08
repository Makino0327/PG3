#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>

// =========================
// CSV -> 2次元 int 配列
// =========================
static std::vector<std::vector<int>> LoadCsvMap(const std::string& path) {
    std::ifstream ifs(path);
    if (!ifs.is_open()) {
        return {};
    }

    std::vector<std::vector<int>> map;
    std::string line;

    while (std::getline(ifs, line)) {
        if (line.empty()) continue;

        std::vector<int> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            // 空白が混じっても stoi できることが多い（" 1" など）
            row.push_back(std::stoi(cell));
        }

        if (!row.empty()) map.push_back(row);
    }

    return map;
}

// =========================
// 簡易描画
// =========================
static char TileToChar(int v) {
    if (v == 0) return '0';
    if (v == 1) return '1';
    if (v == 2) return '2';
    if (v == 3) return '3';
    return '*';
}

static void DrawMapConsole(const std::vector<std::vector<int>>& map) {
    if (map.empty()) {
        std::cout << "[map is empty]\n";
        return;
    }

    for (int y = 0; y < (int)map.size(); ++y) {
        for (int x = 0; x < (int)map[y].size(); ++x) {
            std::cout << TileToChar(map[y][x]) << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    // ===== スレッド間共有 =====
    std::mutex mtx;
    std::condition_variable cv;

    // 「バックグラウンドが作ったマップ」を渡す（producer-consumer）
    std::queue<std::vector<std::vector<int>>> q;

    bool exitFlag = false;

    // メインが表示するマップ
    std::vector<std::vector<int>> currentMap;
    bool loaded = false;

    // ===== バックグラウンド：CSV読み込み =====
    std::thread th([&]() {
        // 「時間がかかる処理」を演出（本当はCSVが重い想定）
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        auto mapData = LoadCsvMap("map.csv");

        {
            std::lock_guard<std::mutex> lock(mtx);
            q.push(std::move(mapData));
        }
        cv.notify_one();

        // 終了待ち（join できるように生かしておく）
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]() { return exitFlag; });
        });

    // ===== メインループ=====
    for (;;) {
        // まだ読み込みが終わっていないなら、キュー待ち
        if (!loaded) {
            std::unique_lock<std::mutex> lock(mtx);

            // ★資料の肝：条件付き wait
            cv.wait(lock, [&]() { return !q.empty(); });

            currentMap = std::move(q.front());
            q.pop();
            loaded = true;

            // 受け取ったら表示
            DrawMapConsole(currentMap);
        }

        // ここは「ゲームが動いてる」代わり（CPUを食い過ぎない）
        std::this_thread::sleep_for(std::chrono::milliseconds(16));

        if (loaded) {
            std::string dummy;
            std::getline(std::cin, dummy);
            break;
        }
    }

    // ===== 終了処理 =====
    {
        std::lock_guard<std::mutex> lock(mtx);
        exitFlag = true;
    }
    cv.notify_all();

    if (th.joinable()) {
        th.join();
    }

    return 0;
}

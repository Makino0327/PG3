#include <iostream>
#include <functional>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

int main() {
    srand((unsigned int)time(nullptr));

    int userGuess = 0;
    std::cout << "サイコロの出目を予想してください。\n";
    std::cout << "奇数（半）= 1, 偶数（丁）= 0 を入力：";
    std::cin >> userGuess;

    if (userGuess != 0 && userGuess != 1) {
        std::cout << "入力が無効です。0か1を入力してください。\n";
        return 1;
    }

    // サイコロを振る（1～6）
    int roll = rand() % 6 + 1;

    // 結果表示のラムダ式
    std::function<void(int, int)> showResult = [](int roll, int userGuess) {
        std::cout << "\nサイコロの出目は " << roll << " です。\n";
        int isOdd = roll % 2;
        if (isOdd == userGuess)
            std::cout << "→ 正解です！\n";
        else
            std::cout << "→ 不正解です。\n";
        };

    // ラムダ式
    auto delayReveal = [&](int delayMs, int roll, int userGuess,
        std::function<void(int, int)> callback) {
            std::cout << "\n結果を表示します...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            callback(roll, userGuess);
        };

    // 呼び出し
    delayReveal(3000, roll, userGuess, showResult);

    return 0;
}

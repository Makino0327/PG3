#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <Windows.h>  // SetConsoleOutputCP用

// 関数テンプレート
template <typename T>
T Min(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    // コンソール出力をUTF-8に設定
    SetConsoleOutputCP(65001);

    int i1 = 10, i2 = 20;
    float f1 = 3.5f, f2 = 2.8f;
    double d1 = 5.67, d2 = 8.12;

    std::cout << u8"int型: " << i1 << " < " << i2 << u8" → " << Min(i1, i2) << std::endl;
    std::cout << u8"float型: " << f1 << " < " << f2 << u8" → " << Min(f1, f2) << std::endl;
    std::cout << u8"double型: " << d1 << " < " << d2 << u8" → " << Min(d1, d2) << std::endl;

    return 0;
}

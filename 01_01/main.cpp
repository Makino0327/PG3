#include <iostream>
#include <list>
#include <cstring>
#include <windows.h>

using namespace std;

int main() {
	// 1970年の山手線の駅一覧
    list<const char*> y1970{
        "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi",
        "Yurakucho", "Tokyo", "Kanda", "Akihabara",
        "Okachimachi", "Ueno", "Uguisudani", "Nippori",
        "Tabata", "Komagome", "Sugamo", "Otsuka",
        "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo",
        "Shinjuku", "Yoyogi", "Harajuku", "Shibuya",
        "Ebisu", "Meguro", "Gotanda", "Osaki",
        "Shinagawa"
    };

    // 西日暮里を追加
    list<const char*> y2019 = y1970;
    for (auto itr = y2019.begin(); itr != y2019.end(); ++itr) {
        if (strcmp(*itr, "Nippori") == 0) {
            y2019.insert(next(itr), "Nishi-Nippori");
            break;
        }
    }

    // 高輪ゲートウェイを追加
    list<const char*> y2022 = y2019;
    for (auto itr = y2022.begin(); itr != y2022.end(); ++itr) {
        if (strcmp(*itr, "Tamachi") == 0) {
            y2022.insert(next(itr), "Takanawa Gateway");
            break;
        }
    }

    SetConsoleOutputCP(65001);
    // 1970年
    cout << u8"[1970年の駅一覧]\n";
    for (auto itr = y1970.begin(); itr != y1970.end(); ++itr) {
        cout << *itr;
        if (next(itr) != y1970.end()) cout << " -> ";
    }
    cout << "\n\n";

    // 2019年
    cout << u8"[2019年の駅一覧]\n";
    for (auto itr = y2019.begin(); itr != y2019.end(); ++itr) {
        cout << *itr;
        if (next(itr) != y2019.end()) cout << " -> ";
    }
    cout << "\n\n";

    // 2022年
    cout << u8"[2022年の駅一覧]\n";
    for (auto itr = y2022.begin(); itr != y2022.end(); ++itr) {
        cout << *itr;
        if (next(itr) != y2022.end()) cout << " -> ";
    }
    cout << endl;

    return 0;
}

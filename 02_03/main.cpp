#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 

// 関数
typedef void (*ResultFunc)(int, int);

// === 結果表示関数 ===
void ShowResult(int roll, int userGuess) {
    printf("\nサイコロの出目は %d です。\n", roll);
    int isOdd = roll % 2; 
    if (isOdd == userGuess) {
        printf("→ 正解です！\n");
    } else {
        printf("→ 不正解です。\n");
    }
}

// === 遅延実行関数 ===
void DelayReveal(ResultFunc fn, unsigned int delayMs, int roll, int userGuess) {
    printf("\n結果を表示します...\n");
    Sleep(delayMs); 
    fn(roll, userGuess); 
}

// === メイン関数 ===
int main(void) {
    srand((unsigned int)time(NULL));

    int userGuess = 0;
    printf("サイコロの出目を予想してください。\n");
    printf("奇数（半）= 1, 偶数（丁）= 0 を入力：");
    scanf_s("%d", &userGuess);

    if (userGuess != 0 && userGuess != 1) {
        printf("入力が無効です。0か1を入力してください。\n");
        return 1;
    }

    int roll = rand() % 6 + 1;

    DelayReveal(ShowResult, 3000, roll, userGuess);

    return 0;
}

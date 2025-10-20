#include <stdio.h>
#include <Windows.h>

// 一般的な賃金体系
int NormalSalary(int hours) {
    return 1226 * hours;
}

// 再帰的な賃金体系
int RecursiveWage(int hour) {
    if (hour == 1) return 100;               
    return RecursiveWage(hour - 1) * 2 - 50;  
}

// 再帰的に合計賃金を求める関数
int TotalRecursiveSalary(int hour) {
    if (hour == 1) return 100;
    return TotalRecursiveSalary(hour - 1) + RecursiveWage(hour);
}

int main(void) {
    int hours = 1;
    SetConsoleOutputCP(65001);
    // 一般的な賃金と再帰賃金を比較
    while (1) {
        int normal = NormalSalary(hours);
        int re_salary = TotalRecursiveSalary(hours);

        printf(u8"%2d時間 → 一般:%6d円, 再帰的:%8d円\n", hours, normal, re_salary);

        if (re_salary > normal) {
           
            break;
        }
        hours++;
    }

    return 0;
}

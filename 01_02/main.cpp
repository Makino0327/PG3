#include <algorithm>
#include <windows.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string> // std::getline を使用するために必要

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
   ifstream file("PG3_2025_01_02.txt");
   if (!file.is_open()) {
       cerr << u8"ファイルを開けませんでした。" << endl;
       return 1;
   }

   vector<string> studentIDs;
   string line;

   // ASCIIテキストファイルを1行ずつパース
   while (getline(file, line, ',')) {
       // 改行・空行をスキップ（パース処理）
       if (!line.empty()) {
           studentIDs.push_back(line);
       }
   }

   file.close(); // ファイルを閉じる

  

   cout << u8"=== 学籍番号一覧 ===" << endl;
   for (int i = 0; i < studentIDs.size(); i++) {
       cout << studentIDs[i] << endl;
   }

   // 昇順にソート（ASCIIコード順）
   sort(studentIDs.begin(), studentIDs.end());

   // 結果を表示
   cout << u8"=== 学籍番号一覧（昇順） ===" << endl;
   for (int i = 0;i< studentIDs.size();i++){
       cout << studentIDs[i] << endl;
   }

   return 0;
}
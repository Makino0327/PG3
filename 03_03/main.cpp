#include "Car.h"
#include "Bicycle.h"

int main() {

    Vehicle* vehicles[2];

    // インスタンス生成
    vehicles[0] = new Car();
    vehicles[1] = new Bicycle();

    // 実行（ポリモーフィズム）
    for (int i = 0; i < 2; i++) {
        vehicles[i]->Run();
    }

    // 破棄
    for (int i = 0; i < 2; i++) {
        delete vehicles[i];
    }

    return 0;
}

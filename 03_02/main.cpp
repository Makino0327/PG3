#include <iostream>
using namespace std;

// クラステンプレート
template <typename T1, typename T2>
class MinClass {
private:
	T1 a;
	T2 b;

public:
	// コンストラクタ
	MinClass(T1 a, T2 b) : a(a), b(b) {}

	// 小さい値を返すメンバ関数
	auto Min() {
		return (a < b) ? a : b;
	}
};

int main() {

	// 同じ型（3パターン）
	MinClass<int, int> m1(10, 20);
	MinClass<float, float> m2(3.5f, 1.2f);
	MinClass<double, double> m3(8.4, 9.1);

	// 異なる型（3パターン）
	MinClass<int, float> m4(5, 2.5f);
	MinClass<int, double> m5(7, 3.14);
	MinClass<float, double> m6(6.8f, 9.9);

	// 呼び出し
	cout << m1.Min() << endl;
	cout << m2.Min() << endl;
	cout << m3.Min() << endl;
	cout << m4.Min() << endl;
	cout << m5.Min() << endl;
	cout << m6.Min() << endl;

	return 0;
}

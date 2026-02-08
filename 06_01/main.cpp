#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int step = 1;

void PrintThread(int id) {
	std::unique_lock<std::mutex> lock(mtx);

	// 自分の番になるまで待つ
	cv.wait(lock, [&]() { return step == id; });

	std::cout << "thread " << id << std::endl;

	// 次のスレッドへ
	step++;
	cv.notify_all();
}

int main() {
	std::thread t1(PrintThread, 1);
	std::thread t2(PrintThread, 2);
	std::thread t3(PrintThread, 3);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker_thread() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });

    std::cout << "Worker thread is processing data...\n";
}

void publisher_thread() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
        std::cout << "Publisher: Data is ready!\n";
    }

    cv.notify_one();
}

int main() {
    std::thread t1(worker_thread);
    std::thread t2(publisher_thread);

    t1.join();
    t2.join();
    return 0;
}

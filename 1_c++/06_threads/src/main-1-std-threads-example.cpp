#include <cstdio>
#include <memory>
#include <mutex>
#include <thread>

class AccessCounter {
  private:
    std::mutex mtx_;
    int count_ = 0;

  public:
    void increment() {
        std::lock_guard<std::mutex> lock(mtx_);
        ++count_;
    }

    int get_count() {
        std::lock_guard<std::mutex> lock(mtx_);
        return count_;
    }
};

int main() {
    auto counter = std::make_unique<AccessCounter>();

    std::thread t1([&counter]() { counter->increment(); });
    std::thread t2([&counter]() {
        for (int i = 0; i < 1000; ++i) {
            counter->increment();
        }
    });

    std::thread t3([&counter]() { counter->increment(); });

    t1.join();
    t2.join();
    t3.join();

    printf("Final count: %d\n", counter->get_count());
}
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

    std::jthread t1([&counter]() { counter->increment(); });
    std::jthread t2([&counter]() {
        for (int i = 0; i < 1000; ++i) {
            counter->increment();
        }
    });

    std::jthread t3([&counter]() { counter->increment(); });

    // While std::jthread automatically joins when thread objects out of scope
    // It wont crash you program, but you still need to join here to wait all threads to complete
    // to get the final count correctly
    t1.join();
    t2.join();
    t3.join();

    printf("Final count: %d\n", counter->get_count());
}
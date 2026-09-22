#include <iostream>
#include <memory>

class Destructable {
  public:
    ~Destructable() { std::cout << "The instance of the Destructable is destructed" << std::endl; }
};

void unique_ptr_example() {
    auto ptr1 = std::make_unique<Destructable>();
    auto ptr2 = std::move(ptr1);
}

void shared_ptr_example() {
    auto ptr1 = std::make_shared<Destructable>();
    std::cout << "use_count:" << ptr1.use_count() << std::endl;

    {
        auto ptr2 = ptr1;
        auto ptr3 = ptr1;
        std::cout << "use_count:" << ptr1.use_count() << std::endl;
    }

    std::cout << "use_count:" << ptr1.use_count() << std::endl;
}

void weak_ptr_example() {
    std::weak_ptr<Destructable> observer;

    {
        auto ptr1 = std::make_shared<Destructable>();
        observer = ptr1;

        std::cout << "use_count:" << ptr1.use_count() << std::endl;
    }

    auto observer_ptr = observer.lock();
    if (observer_ptr == nullptr) {
        std::cout << "The shared object is destructed, lock() returned nullptr" << std::endl;
    }
}

int main() {
    std::cout << "unique_ptr_example:" << std::endl;
    unique_ptr_example();
    std::cout << std::endl;

    std::cout << "shared_ptr_example:" << std::endl;
    shared_ptr_example();
    std::cout << std::endl;

    std::cout << "weak_ptr_example:" << std::endl;
    weak_ptr_example();
    std::cout << std::endl;

    return 0;
}
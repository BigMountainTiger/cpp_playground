#include <iostream>

int main() {
    int original = 0;

    // A reference variable
    int& ref = original;

    original++;
    std::cout << "original = " << original << std::endl;
    std::cout << "ref = " << ref << std::endl;

    ref++;
    std::cout << std::endl;
    std::cout << "original = " << original << std::endl;
    std::cout << "ref = " << ref << std::endl;

    {
        int& another_ref = original;
        another_ref++;

        // another_ref will be out of scope
    }

    std::cout << std::endl;
    std::cout << "original = " << original << std::endl;

    return 0;
}
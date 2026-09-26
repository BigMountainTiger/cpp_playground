#include <iostream>
#include <string>
#include <string_view>

void test_by_string_view() {
    std::string_view view;

    {
        std::string local_str = "I will disappear soon";
        view = local_str;
    }

    std::cout << "local_str has gone out of scope, result is undefined:" << std::endl;
    std::cout << view << std::endl;
}

void test_by_pointer() {
    const char* broken_pointer = nullptr;

    {
        std::string secret = "Temporary Data";
        broken_pointer = secret.c_str();
    }

    std::cout << std::endl;
    std::cout << "broken_pointer points to deallocated memory:" << std::endl;
    std::cout << broken_pointer << std::endl;
}

void test_by_temporary_string() {
    // The std::string("Temporary string") is out of scope right after this line
    std::string_view view = std::string("Temporary string");

    std::cout << std::endl;
    std::cout << "view points to deallocated memory:" << std::endl;
    std::cout << view << std::endl;
}

int main() {
    test_by_string_view();
    test_by_pointer();
    test_by_temporary_string();

    return 0;
}
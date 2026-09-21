#include "../include/animals/animal.h"
#include "../include/animals/cat.h"
#include "../include/animals/dog.h"
#include <array>
#include <iostream>
#include <memory>

int main() {
    std::array<std::unique_ptr<Animal>, 3> animals;
    animals[0] = std::make_unique<Animal>();
    animals[1] = std::make_unique<Dog>();
    animals[2] = std::make_unique<Cat>();

    for (const auto& animal : animals) {
        std::cout << animal->get_name() << " - " << animal->get_sound()
                  << std::endl;
    }

    return 0;
}
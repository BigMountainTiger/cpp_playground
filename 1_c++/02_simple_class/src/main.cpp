#include "../include/animals/animal.h"
#include "../include/animals/cat.h"
#include "../include/animals/dog.h"
#include <array>
#include <iostream>
#include <memory>
#include <vector>

int main() {

    {
        // Use array
        std::array<std::unique_ptr<Animal>, 3> animals;
        animals[0] = std::make_unique<Animal>();
        animals[1] = std::make_unique<Dog>();
        animals[2] = std::make_unique<Cat>();

        for (const auto& animal : animals) {
            std::cout << animal->get_name() << " - " << animal->get_sound() << std::endl;
        }

        std::cout << std::endl;
    }

    {
        // Use vector
        std::vector<std::unique_ptr<Animal>> animals;
        animals.reserve(100);

        animals.push_back(std::make_unique<Animal>());
        animals.push_back(std::make_unique<Dog>());
        animals.push_back(std::make_unique<Cat>());

        for (const auto& animal : animals) {
            std::cout << animal->get_name() << " - " << animal->get_sound() << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
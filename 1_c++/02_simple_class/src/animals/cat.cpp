#include "../../include/animals/cat.h"
#include <string>

Cat::Cat() { name_ = "Cat"; }

std::string Cat::get_sound() { return "Meow"; }

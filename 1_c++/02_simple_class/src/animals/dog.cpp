#include "../../include/animals/dog.h"
#include <string>

Dog::Dog() { name_ = "Dog"; }

std::string Dog::get_sound() { return "Bark"; }

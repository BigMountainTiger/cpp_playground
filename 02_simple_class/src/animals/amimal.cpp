#include "../../include/animals/animal.h"
#include <string>

Animal::Animal() { name_ = "Generic animal"; }

std::string Animal::get_name() { return name_; }

std::string Animal::get_sound() { return "Generic animal sound"; }
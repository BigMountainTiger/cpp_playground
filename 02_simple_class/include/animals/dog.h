#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include <string>

class Dog : public Animal {

  public:
    Dog();
    std::string get_sound() override;
};

#endif
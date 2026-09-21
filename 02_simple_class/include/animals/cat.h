#ifndef CAT_H
#define CAT_H

#include "animal.h"
#include <string>

class Cat : public Animal {

  public:
    Cat();
    std::string get_sound() override;
};

#endif
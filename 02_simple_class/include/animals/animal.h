#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal {
  protected:
    std::string name_;

  public:
    Animal();
    virtual ~Animal() = default;

    virtual std::string get_name();
    virtual std::string get_sound();
};

#endif
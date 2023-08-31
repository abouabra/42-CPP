#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal();
    Animal(std::string Type);
    Animal(const Animal &instance);
    Animal& operator=(const Animal &instance);
    virtual ~Animal();

    virtual void makeSound() = 0;
    std::string getType();
};

#endif
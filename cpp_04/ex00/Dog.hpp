#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog: public Animal {
public:
    Dog();
    Dog(const Dog &instance);
    Dog& operator=(const Dog &instance);
    ~Dog();
    
    void makeSound();
    std::string getType();
};

#endif
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal {
private:
    Brain *brain;
public:
    Dog();
    Dog(const Dog &instance);
    Dog& operator=(const Dog &instance);
    ~Dog();
    
    void makeSound() const;
    std::string getType();
};

#endif
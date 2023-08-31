#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public Animal {
private:
    Brain *brain;
public:
    Cat();
    Cat(const Cat &instance);
    Cat& operator=(const Cat &instance);
    ~Cat();
    
    void makeSound();
    std::string getType();
};

#endif
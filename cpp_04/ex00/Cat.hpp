#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat: public Animal {
public:
    Cat();
    Cat(const Cat &instance);
    Cat& operator=(const Cat &instance);
    ~Cat();
    
    void makeSound() const;
    std::string getType();
};

#endif
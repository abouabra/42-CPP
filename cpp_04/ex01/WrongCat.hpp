#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat &instance);
    WrongCat& operator=(const WrongCat &instance);
    ~WrongCat();
    
    void makeSound() const;
    std::string getType();
};

#endif
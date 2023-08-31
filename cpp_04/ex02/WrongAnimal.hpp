#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(std::string Type);
    WrongAnimal(const WrongAnimal &instance);
    WrongAnimal& operator=(const WrongAnimal &instance);
    ~WrongAnimal();

    void makeSound();
    std::string getType();
};

#endif
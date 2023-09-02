#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "WrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string Type)
{
    type = Type;
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}
std::string WrongAnimal::getType()
{
    return type;
}
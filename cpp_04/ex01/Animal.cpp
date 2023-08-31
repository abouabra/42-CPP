#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string Type)
{
    type = Type;
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = obj;
}

Animal& Animal::operator=(const Animal &obj)
{
    std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound()
{
    std::cout << "Animal Sound" << std::endl;
}
std::string Animal::getType()
{
    return type;
}
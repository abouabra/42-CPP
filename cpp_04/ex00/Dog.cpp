#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog():Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    *this = obj;
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Dog Sound" << std::endl;
}
std::string Dog::getType()
{
    return type;
}
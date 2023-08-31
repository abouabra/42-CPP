#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
    std::cout << "Cat Copy constructor called" << std::endl;
    *this = obj;
}

Cat& Cat::operator=(const Cat &obj)
{
    std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound()
{
    std::cout << "Cat Sound" << std::endl;
}
std::string Cat::getType()
{
    return type;
}
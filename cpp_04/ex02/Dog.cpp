#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog():Animal("Dog")
{
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog Copy constructor called" << std::endl;
    this->brain = new Brain;
    *this = obj;
}

Dog& Dog::operator=(const Dog &obj)
{
    std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        *brain = *(obj.brain);
        this->type = obj.type;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
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
#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    if (this != &obj)
        this->type = obj.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat Sound" << std::endl;
}
std::string WrongCat::getType()
{
    return type;
}
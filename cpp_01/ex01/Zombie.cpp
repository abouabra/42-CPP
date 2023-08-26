#include "Zombie.hpp"

Zombie::Zombie()
{
    Name = "Default";
}

Zombie::Zombie(std::string name)
{
    Name = name;
}

Zombie::Zombie(const Zombie &obj)
{
    *this = obj;
}

Zombie& Zombie::operator=(const Zombie &obj)
{
    if (this != &obj)
        this->Name = obj.Name;
    return *this;
}

Zombie::~Zombie()
{
    std::cout << this->Name <<  ": Is DEAD" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->Name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::SetName(std::string name)
{
    Name = name;
}

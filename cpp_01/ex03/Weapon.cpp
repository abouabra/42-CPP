#include "Weapon.hpp"

Weapon::Weapon()
{
    type = "No Weapon";
}
Weapon::Weapon(std::string Type)
{
    type = Type;
}

Weapon::~Weapon()
{

}

const std::string Weapon::getType(void)
{
    return type;
}

void Weapon::setType(std::string Type)
{
    type = Type;
}


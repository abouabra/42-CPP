#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string Name)
{
    name = Name;
    weapon = NULL;
}
HumanB::~HumanB()
{

}
void HumanB::attack()
{
    if(weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " attacks with No Weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
    weapon = &Weapon;
}

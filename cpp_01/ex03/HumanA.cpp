#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string Name, Weapon &Weapon):weapon(Weapon)
{
    name = Name;
    weapon = Weapon;
}
HumanA::~HumanA()
{

}
void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
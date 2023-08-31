#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    name = "Default";
    for(int i=0; i < 4; i++)
        inventory[i] = NULL;
}
Character::Character(std::string Name)
{
    name = Name;
    for(int i=0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &obj)
{
    *this = obj;
}

Character& Character::operator=(const Character &obj)
{

    if (this != &obj)
    {

    }
    return *this;
}

Character::~Character()
{

}

std::string const & Character::getName() const
{
    return name;
}
void Character::equip(AMateria* m)
{
    int i=-1;
    while(++i < 4 && inventory[i])
        ;
    if(i <= 4)
        inventory[i] = m;
    else
    {
        std::cout << "inventory full" << std::endl;
    }
}

void Character::unequip(int idx)
{

}

void Character::use(int idx, ICharacter& target)
{
    if(idx >= 0 && idx <= 4)
    {
        inventory[idx]->AMateria::use(target);
    }
    else
    {
        std::cout << "enter valid idx" << std::endl;
    }
}
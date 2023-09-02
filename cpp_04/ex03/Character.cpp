#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    name = "Default";
    for(int i=0; i < 4; i++)
    {
        inventory[i] = NULL;
        floor[i] = NULL;
    }
}

Character::Character(std::string Name)
{
    name = Name;
    for(int i=0; i < 4; i++)
    {
        inventory[i] = NULL;
        floor[i] = NULL;
    }
}

Character::Character(const Character &obj)
{
    name = obj.name;
    for (int i = 0; i < 4; i++)
    {
        if (obj.inventory[i])
            inventory[i] = obj.inventory[i]->clone();
        else
            inventory[i] = NULL;
        floor[i] = NULL;
    }
}

Character& Character::operator=(const Character &obj)
{
    if (this != &obj)
    {
        name = obj.name;
        for (int i = 0; i < 4; i++)
        {
            if(inventory[i])
                delete inventory[i];
            if (obj.inventory[i])
                inventory[i] = obj.inventory[i]->clone();
            else
                inventory[i] = NULL;
            floor[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for(int i = 0;i < 4; i++)
    {
        if(inventory[i])
            delete inventory[i];
        if(floor[i])
            delete floor[i];
    }
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for(int i = 0;i < 4; i++)
    {
        if(floor[i])
        {
            delete floor[i];
            floor[i] = NULL;
        }
    }
    int i=-1;
    while(++i < 4 && inventory[i])
        ;
    if(i <= 4)
        inventory[i] = m;
    else
        std::cout << "inventory full" << std::endl;
}

void Character::unequip(int idx)
{
    if(idx >= 0 && idx <= 4)
    {
        if(inventory[idx] == NULL)
        {
            std::cout << "item alredy inequiped" << std::endl;
            return;
        }
        int i=-1;
        while(++i < 4 && floor[i])
            ;
        floor[i] = inventory[idx];
        inventory[idx] = NULL;
    }
    else
    {
        std::cout << "enter valid idx" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if(idx >= 0 && idx <= 4)
    {
        if(inventory[idx] == NULL)
        {
            std::cout << "empty inventory slot" << std::endl;
            return;
        }
        inventory[idx]->use(target);
    }
    else
    {
        std::cout << "enter valid idx" << std::endl;
    }
}
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
{
    name = "Default";
    slot_index = 0;
    for(int i=0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(std::string Name)
{
    name = Name;
    slot_index = 0;
    for(int i=0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character &obj)
{
    name = obj.name;
    for (int i = 0; i < 4; i++)
    {
        if (obj.inventory[i])
        {
            inventory[i] = obj.inventory[i]->clone();
            for(int j=0; j < slot_index; j++)
                if(all_slots[j] == obj.inventory[i])
                    return;
            slot_index++;
            AMateria **tmp_slots = new AMateria*[slot_index];
            int j=-1;
            while(++j < slot_index -1)
                tmp_slots[j] = all_slots[j];
            tmp_slots[j] = obj.inventory[i];
            delete [] all_slots;
            all_slots = tmp_slots;
        }
        else
            inventory[i] = NULL;
    }
}

Character& Character::operator=(const Character &obj)
{

    if (this != &obj)
    {
        name = obj.name;
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];

            if (obj.inventory[i])
                inventory[i] = obj.inventory[i]->clone();
            else
                inventory[i] = NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    delete [] all_slots;
    // for(int i = 0;i < 4; i++)
    //     delete inventory[i];
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
    {
        inventory[i] = m;

        for(int i=0; i < slot_index; i++)
            if(all_slots[i] == m)
                return;
        slot_index++;
        AMateria **tmp_slots = new AMateria*[slot_index];
        int j=-1;
        while(++j < slot_index -1)
            tmp_slots[j] = all_slots[j];
        tmp_slots[j] = m;
        delete [] all_slots;
        all_slots = tmp_slots;
    }
    else
    {
        std::cout << "inventory full" << std::endl;
    }
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
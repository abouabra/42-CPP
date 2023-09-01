#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
    type = "Default";
    slot_index = 0;
    for(int i=0; i < 4; i++)
        inventory[i] = NULL;
}

MateriaSource::MateriaSource(std::string Type)
{
    type = Type;
    slot_index = 0;
    for(int i=0; i < 4; i++)
        inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    *this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{

    if (this != &obj)
    {

    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    delete [] all_slots;
    // for(int i = 0;i < 4; i++)
    //     delete inventory[i];
}

void MateriaSource::learnMateria(AMateria* m)
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

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i=-1;
    while(++i < 4)
    {
        if(inventory[i]->getType() == type)
        {
            if(type == "cure")
                return new Cure();
            else if(type == "ice")
                return new Ice();
        }
    }
    return 0;
    // if(idx >= 0 && idx <= 4)
    // {
    //     if(inventory[idx] == NULL)
    //     {
    //         std::cout << "empty inventory slot" << std::endl;
    //         return;
    //     }
    //     inventory[idx]->use(target);
    // }
    // else
    // {
    //     std::cout << "enter valid idx" << std::endl;
    // }
}
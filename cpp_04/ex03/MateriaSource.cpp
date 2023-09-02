#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
    type = "Default";
    slot_index = 0;
    for(int i=0; i < 4; i++)
        learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(std::string Type)
{
    type = Type;
    slot_index = 0;
    for(int i=0; i < 4; i++)
        learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    // *this = obj;
    type = obj.type;
    for (int i = 0; i < 4; i++)
    {
        if (obj.learnedMaterias[i])
        {
            learnedMaterias[i] = obj.learnedMaterias[i]->clone();
            for(int j=0; j < slot_index; j++)
                if(all_slots[j] == obj.learnedMaterias[i])
                    return;
            slot_index++;
            AMateria **tmp_slots = new AMateria*[slot_index];
            int j=-1;
            while(++j < slot_index -1)
                tmp_slots[j] = all_slots[j];
            tmp_slots[j] = obj.learnedMaterias[i];
            delete [] all_slots;
            all_slots = tmp_slots;
        }
        else
            learnedMaterias[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj)
{

    if (this != &obj)
    {
        type = obj.type;
        for (int i = 0; i < 4; i++)
        {
            // delete inventory[i];
            if (obj.learnedMaterias[i])
            {
                learnedMaterias[i] = obj.learnedMaterias[i]->clone();
                for(int j=0; j < slot_index; j++)
                    if(all_slots[j] == obj.learnedMaterias[i])
                        return *this;
                slot_index++;
                AMateria **tmp_slots = new AMateria*[slot_index];
                int j=-1;
                while(++j < slot_index -1)
                    tmp_slots[j] = all_slots[j];
                tmp_slots[j] = obj.learnedMaterias[i];
                delete [] all_slots;
                all_slots = tmp_slots;
            }
            else
                learnedMaterias[i] = NULL;
        }
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
    while(++i < 4 && learnedMaterias[i])
        ;
    if(i <= 4)
    {
        learnedMaterias[i] = m;
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
        if(learnedMaterias[i]->getType() == type)
        {
            return learnedMaterias[i]->clone();
        }
    }
    return 0;
}
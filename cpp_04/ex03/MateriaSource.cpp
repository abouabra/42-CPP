#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource()
{
    type = "Default";
    for(int i=0; i < 4; i++)
        learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(std::string Type)
{
    type = Type;
    for(int i=0; i < 4; i++)
        learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    type = obj.type;
    for (int i = 0; i < 4; i++)
    {
        if (obj.learnedMaterias[i])
            learnedMaterias[i] = obj.learnedMaterias[i]->clone();
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
            if(learnedMaterias[i])
                delete learnedMaterias[i];
            if (obj.learnedMaterias[i])
                learnedMaterias[i] = obj.learnedMaterias[i]->clone();
            else
                learnedMaterias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0;i < 4; i++)
        if(learnedMaterias[i])
            delete learnedMaterias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    int i=-1;
    while(++i < 4 && learnedMaterias[i])
        ;
    if(i <= 4)
        learnedMaterias[i] = m;
    else
        std::cout << "cannot learn because inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i=-1;
    while(++i < 4)
        if(learnedMaterias[i]->getType() == type)
            return learnedMaterias[i]->clone();
    std::cout << "Type not found" << std::endl;
    return 0;
}
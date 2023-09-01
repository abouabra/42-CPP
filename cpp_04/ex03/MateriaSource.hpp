#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

// #include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource: public IMateriaSource {
private:
    std::string type;
    AMateria *inventory[4];
    AMateria **all_slots;
    int slot_index;
public:
    MateriaSource();
    MateriaSource(std::string Type);
    MateriaSource(const MateriaSource &instance);
    MateriaSource& operator=(const MateriaSource &instance);
    ~MateriaSource();

    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const & type);

};

#endif
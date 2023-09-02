#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource: public IMateriaSource {
private:
    std::string type;
    AMateria *learnedMaterias[4];
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
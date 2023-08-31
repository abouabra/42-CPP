#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include <iostream>

class Ice: public AMateria {
public:
    Ice();
    Ice(const Ice &instance);
    Ice& operator=(const Ice &instance);
    ~Ice();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
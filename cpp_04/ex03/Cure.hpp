#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure: public AMateria {
public:
    Cure();
    Cure(const Cure &instance);
    Cure& operator=(const Cure &instance);
    ~Cure();

    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif
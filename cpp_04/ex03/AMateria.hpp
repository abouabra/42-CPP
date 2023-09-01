#ifndef AMATERIA_HPP
#define AMATERIA_HPP
// #pragma once

#include <iostream>


#include "ICharacter.hpp"
// class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
    AMateria(std::string const & type);
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    virtual ~AMateria();
    AMateria(const AMateria &instance);
    AMateria& operator=(const AMateria &instance);
};
#endif
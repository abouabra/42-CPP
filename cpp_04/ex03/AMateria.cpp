#include "AMateria.hpp"

AMateria::AMateria(std::string const &Type)
{
    type = Type;
}
std::string const &AMateria::getType() const
{
    return type;
}

AMateria::~AMateria()
{

}

virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
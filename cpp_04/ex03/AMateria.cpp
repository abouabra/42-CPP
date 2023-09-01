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

void AMateria::use(ICharacter& target)
{
    std::cout << "* AMateria " << target.getName() << "'s use function *" << std::endl;
}
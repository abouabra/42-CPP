#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure():AMateria("cure")
{

}
Cure::Cure(const Cure &instance):AMateria("cure")
{
    *this = instance;
}
Cure& Cure::operator=(const Cure &instance)
{
    if(this != &instance)
    {
        
    }
    return *this;
}
Cure::~Cure()
{

}

AMateria* Cure::clone() const
{
    Cure *cure = new Cure();
    return cure;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

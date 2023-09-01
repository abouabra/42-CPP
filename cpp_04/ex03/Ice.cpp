#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice():AMateria("ice")
{

}
Ice::Ice(const Ice &instance):AMateria("ice")
{
    *this = instance;
}
Ice& Ice::operator=(const Ice &instance)
{
    if(this != &instance)
    {
        type = instance.type;
    }
    return *this;
}
Ice::~Ice()
{

}

AMateria* Ice::clone() const
{
    Ice *ice = new Ice();
    return ice;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl;
}

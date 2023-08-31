#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default",100,30,100)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name ,100,30,100)
{
    std::cout << "FragTrap Name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &instance)
{
    *this = instance;
}
FragTrap& FragTrap::operator = (const FragTrap& FragTrap)
{
    if(this != &FragTrap)
    {
        std::cout << "FragTrap "<< FragTrap.Name <<" copied into " << this->Name << std::endl;
        this->Name = FragTrap.Name;
        this->HitPoints = FragTrap.HitPoints;
        this->EnergyPoints = FragTrap.EnergyPoints;
        this->AttackDamage = FragTrap.AttackDamage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap "<< this->Name <<" sends you a positive high five" << std::endl;
}
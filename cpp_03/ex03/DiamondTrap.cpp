#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default_clap_name", 50, 30, 100)
{
    this->Name = "Default";
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string Name): ClapTrap(Name + "_clap_name", 50, 30, 100)
{
    this->Name = Name;
    std::cout << "DiamondTrap Named constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &instance)
{
    *this = instance;
}
DiamondTrap& DiamondTrap::operator = (const DiamondTrap& DiamondTrap)
{
    if(this != &DiamondTrap)
    {
        std::cout << "DiamondTrap "<< DiamondTrap.Name <<" copied into " << this->Name << std::endl;
        this->Name = DiamondTrap.Name;
        this->HitPoints = DiamondTrap.HitPoints;
        this->EnergyPoints = DiamondTrap.EnergyPoints;
        this->AttackDamage = DiamondTrap.AttackDamage;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

int DiamondTrap::getHP()
{
    return this->HitPoints;
}
int DiamondTrap::getAD()
{
    return this->AttackDamage;
}
int DiamondTrap::getEP()
{
    return this->EnergyPoints;
}
std::string DiamondTrap::getName()
{
    return this->Name;
}
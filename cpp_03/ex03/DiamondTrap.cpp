#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap()
{
    std::cout << "DiamondTrap Default constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(std::string Name): ClapTrap(Name + "_clap_name")
{
    this->Name = Name;
    this->AttackDamage = FragTrap::getAD();
    this->EnergyPoints = ScavTrap::getEP();
    this->HitPoints = FragTrap::getHP();
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
void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}
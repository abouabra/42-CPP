#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default",50,20,100)
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name ,50,20,100)
{
    std::cout << "ScavTrap Name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &instance)
{
    *this = instance;
}
ScavTrap& ScavTrap::operator = (const ScavTrap& Scavtrap)
{
    if(this != &Scavtrap)
    {
        std::cout << "ScavTrap "<< Scavtrap.Name <<" copied into " << this->Name << std::endl;
        this->Name = Scavtrap.Name;
        this->HitPoints = Scavtrap.HitPoints;
        this->EnergyPoints = Scavtrap.EnergyPoints;
        this->AttackDamage = Scavtrap.AttackDamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
    
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap "<< this->Name <<" is now in Gate keeper mode." << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
    if(HitPoints && EnergyPoints)
    {
        std::cout << "ScavTrap " << Name << " attacks " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else
        std::cout << "ScavTrap " << Name << " has no Energy or HitPoints Left." << std::endl;
}
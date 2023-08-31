#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    Name = "Default";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj)
    {
        this->Name = obj.Name;
        this->HitPoints = obj.HitPoints;
        this->EnergyPoints = obj.EnergyPoints;
        this->AttackDamage = obj.AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if(HitPoints && EnergyPoints)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << " causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    }
    else
        std::cout << "ClapTrap " << Name << " has no Energy or HitPoints Left." << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if(HitPoints && EnergyPoints)
    {
        if(HitPoints - (int) amount > 0)
        {
            std::cout << "ClapTrap " << Name << " took " << amount << " points of damage!" << std::endl;
            HitPoints -= amount;
            EnergyPoints--;
        }
        else
        {
            std::cout << "ClapTrap " << Name << " took " << amount << " points of damage! and has no HitPoints left !!!" << std::endl;
            HitPoints = 0;
            EnergyPoints--;
        }
    }
    else
        std::cout << "ClapTrap " << Name << " has no Energy or HitPoints Left." << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(HitPoints && EnergyPoints)
    {
        EnergyPoints--;
        HitPoints+= amount;
        std::cout << "ClapTrap " << Name << " has restored " << amount << " points of hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " has no Energy or HitPoints Left." << std::endl;
}
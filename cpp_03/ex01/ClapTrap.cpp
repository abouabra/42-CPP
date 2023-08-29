#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    Name = "Default";
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "ClapTrap Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
    Name = name;
    HitPoints = 10;
    EnergyPoints = 10;
    AttackDamage = 0;
    std::cout << "ClapTrap Name constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name, int EP, int AD, int HP)
{
    Name = name;
    HitPoints = HP;
    EnergyPoints = EP;
    AttackDamage = AD;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &obj)
{
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
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
    std::cout << "ClapTrap Destructor called" << std::endl;
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

int ClapTrap::getHP()
{
    return this->HitPoints;
}
int ClapTrap::getAD()
{
    return this->AttackDamage;
}
int ClapTrap::getEP()
{
    return this->EnergyPoints;
}
std::string ClapTrap::getName()
{
    return this->Name;
}
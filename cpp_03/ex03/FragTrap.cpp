#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Default",100,30,100)
{
    std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name ,100,30,100)
{
    std::cout << "FragTrap Named constructor called" << std::endl;
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
    std::cout << "FragTrap "<< this->Name <<" request high fives (press inter)" << std::endl;
    std::string line;
    getline(std::cin,line);
}

int FragTrap::getHP()
{
    return 100;
}
int FragTrap::getAD()
{
    return 30;
}
int FragTrap::getEP()
{
    return 100;
}
std::string FragTrap::getName()
{
    return this->Name;
}
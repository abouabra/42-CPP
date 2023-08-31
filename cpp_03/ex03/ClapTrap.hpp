#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
    std::string Name;
    int EnergyPoints;
    int AttackDamage;
    int HitPoints;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &instance);
    ClapTrap& operator=(const ClapTrap &instance);
    virtual ~ClapTrap();

    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    ClapTrap(std::string name, int EP, int AD, int HP);

};

#endif
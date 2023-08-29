#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
    std::string Name;
    int EnergyPoints;
    int AttackDamage;
    int HitPoints;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &instance);
    ClapTrap& operator=(const ClapTrap &instance);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
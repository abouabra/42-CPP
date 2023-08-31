#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string Name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &instance);
        DiamondTrap& operator=(const DiamondTrap &instance);
        ~DiamondTrap();

        int getHP();
        int getEP();
        int getAD();
        std::string getName();
};

#endif
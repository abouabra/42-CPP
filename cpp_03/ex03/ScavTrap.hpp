#ifndef SCAVETRAP_HPP
#define SCAVETRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap {

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &instance);
        ScavTrap& operator=(const ScavTrap &instance);
        ~ScavTrap();

        void guardGate();
        void attack(const std::string& target);

        void highFivesGuys();
        int getHP();
        int getEP();
        int getAD();
        std::string getName();
};

#endif
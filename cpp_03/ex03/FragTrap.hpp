#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &instance);
        FragTrap& operator=(const FragTrap &instance);
        ~FragTrap();
        
        void highFivesGuys();
        int getHP();
        int getEP();
        int getAD();
        std::string getName();
};

#endif
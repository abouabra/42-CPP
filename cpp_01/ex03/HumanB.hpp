#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
private:
    std::string name;
    Weapon *weapon;
public:
    HumanB(std::string Name);
    ~HumanB();

    void attack();
    void setWeapon(Weapon &weapon);
};

#endif
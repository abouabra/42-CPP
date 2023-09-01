#ifndef CHARACTER_HPP
#define CHARACTER_HPP

// #include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character: public ICharacter {
private:
    std::string name;
    AMateria *inventory[4];
    AMateria **all_slots;
    int slot_index;
public:
    Character();
    Character(std::string Name);
    Character(const Character &instance);
    Character& operator=(const Character &instance);
    ~Character();
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif
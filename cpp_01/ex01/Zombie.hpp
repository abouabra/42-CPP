#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
private:
    std::string Name;
public:
    Zombie();
    Zombie(std::string name);
    Zombie(const Zombie &instance);
    Zombie& operator=(const Zombie &instance);
    ~Zombie();

    void announce( void );
    void SetName(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
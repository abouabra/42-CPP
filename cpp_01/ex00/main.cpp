#include "Zombie.hpp"

int main()
{
    Zombie zmb1;
    Zombie zmb2("John Wick");

    zmb1.announce();
    zmb2.announce();

    randomChump("Naruto");
    Zombie *zmb3 = newZombie("Goku");
    zmb3->announce();
    delete zmb3;
    return 0;
}
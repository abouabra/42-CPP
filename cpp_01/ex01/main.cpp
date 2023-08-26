#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *zmb = zombieHorde(N,"Goku");
    for(int i =0; i < N; i++)
        zmb[i].announce();
    delete[] zmb;

    zmb = zombieHorde(N,"Naruto");
    for(int i =0; i < N; i++)
        zmb[i].announce();
    delete[] zmb;
    return 0;
}
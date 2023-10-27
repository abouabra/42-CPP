#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if(ac < 2)
    {
        std::cout << "Usage: ./PmergeMe [numbers]" << std::endl;
        return 1;
    }
    av++;
    
    PmergeMe pm(av);
    pm.run();
    
    return 0;
}

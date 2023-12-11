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
    // pm.set_list_debug_mode(true);
    // pm.set_vect_debug_mode(true);
    pm.merge_insertion_sort_vector();
    pm.merge_insertion_sort_list();
    return 0;
}

// AK-47 Test
// while true; do clear && ./PmergeMe $(jot -r 21 1 10000 | tr '\n' ' ');sleep 0.1 ; done

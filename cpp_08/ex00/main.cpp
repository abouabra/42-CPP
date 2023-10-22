#include "easyfind.hpp"

int main( void )
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
        l.push_back(i);
        d.push_back(i);
    }
    std::cout << "Vector: ";
    try
    {
        std::cout << *easyfind(v, 5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "List: ";
    try
    {
        std::cout << *easyfind(l, 5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Deque: ";
    try
    {
        std::cout << *easyfind(d, 5) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Invalid: ";
    try
    {
        std::cout << *easyfind(v, 11) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

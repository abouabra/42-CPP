#include "Bureaucrat.hpp"
#include <exception>

int main()
{
    try
    {
        Bureaucrat b1("burau1", 2);
        std::cout << b1 << std::endl;
        b1.increment();
        b1.increment();
        Bureaucrat b2("burau2", 1000);
        Bureaucrat b3("burau2", -1);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
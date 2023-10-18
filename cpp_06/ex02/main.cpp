#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *base = generate();
    identify(base);
    std::cout << std::endl;
    identify(*base);
    delete base;

    return 0;
}
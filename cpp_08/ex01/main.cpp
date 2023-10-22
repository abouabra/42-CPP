#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Intra Tests: " << std::endl;
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "Test Empty Span: " << std::endl;
    Span sp2 = Span(10000);
    std::vector<int> v(10000);

    for (int i = 0; i < 10000; i++)
        v[i] = i;
    
    try
    {
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl; }
    std::cout << std::endl;

    
    std::cout << "Test Span Functions: " << std::endl;
    sp2.addNumber<std::vector<int> >(v.begin(), v.end());
    std::cout << sp2.shortestSpan() << std::endl;
    std::cout << sp2.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "Test Full Span: " << std::endl;
    try
    {
        sp2.addNumber(-1);
    }
    catch (std::exception &e) { std::cout << e.what() << std::endl;}

    return 0;
}
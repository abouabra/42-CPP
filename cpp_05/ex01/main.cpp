#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main()
{
    try
    {
        Bureaucrat b1("Nadia Fettah", 27);
        Form form1("9anon maliya 2024", 25, 140);
        std::cout << b1 << std::endl;
        std::cout << form1 << std::endl;
        std::cout << std::boolalpha << form1.Is_Signed() << std::endl;
        form1.beSigned(b1);
        std::cout << std::boolalpha << form1.Is_Signed() << std::endl;
        b1.signForm(form1);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

// int main()
// {
//     try
//     {
//         Bureaucrat b1("Nadia Fettah", 27);
//         ShrubberyCreationForm f1("home");
//         f1.beSigned(b1);
//         b1.executeForm(f1);
//     }
//     catch(std::exception &e)
//     {
//         std::cout << e.what() << std::endl;
//     }
//     return 0;
// }

int	main( void )
{
	AForm		*shrub = new ShrubberyCreationForm("home");
	Bureaucrat	corr("Corrector", 1);
	Bureaucrat	me("Me", 140);

	corr.executeForm(*shrub);
	std::cout << std::endl;
	corr.signForm(*shrub);
	std::cout << *shrub << std::endl;
	std::cout << corr << std::endl;
	corr.executeForm(*shrub);
	me.executeForm(*shrub);
	delete shrub;

	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*robotomy = new RobotomyRequestForm("Corrector");
	Bureaucrat	me2("Me", 1);

	me2.executeForm(*robotomy);
	me2.signForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	me2.executeForm(*robotomy);
	delete robotomy;
	
	std::cout << std::endl;
	std::cout << std::endl;

	AForm		*presidential = new PresidentialPardonForm("Corrector");
	Bureaucrat	me3("Me", 6);

	me3.executeForm(*presidential);
	me3.signForm(*presidential);
	me3.executeForm(*presidential);
	me3.increment();
	me3.executeForm(*presidential);
	delete presidential;

	return (0);
}
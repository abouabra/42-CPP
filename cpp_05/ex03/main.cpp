#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main( void )
{
	try
	{
		Intern	someRandomIntern;
		AForm		*shrub;
		Bureaucrat	bob("Bob", 1);
		shrub	= someRandomIntern.makeForm("shrubbery creation", "home");
		shrub->beSigned(bob);
		shrub->execute(bob);
		std::cout << std::endl;
		std::cout << std::endl;

		Intern	someRandomIntern2;
		AForm		*presidential;
		presidential	= someRandomIntern2.makeForm("Some thing that doesnt work", "You");
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
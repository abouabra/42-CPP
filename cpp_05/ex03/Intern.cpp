#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern()
{
	std::cout << "Default constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Destructor called" << std::endl;
}
AForm *Intern::NewRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}
AForm *Intern::NewPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}
AForm *Intern::NewShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
AForm* Intern::makeForm(std::string form, std::string target)
{
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	AForm *(Intern::*ptr[3])(std::string) = {&Intern::NewRobotomyRequestForm, &Intern::NewPresidentialPardonForm, &Intern::NewShrubberyCreationForm};
	int i = -1;
	while(++i < 3)
	{
		if(form == forms[i])
		{
			std::cout << "Intern creates " << form << std::endl;
			return (this->*ptr[i])(target);
		}
	}
	throw FormDoesNotExistException();
	return NULL;
}
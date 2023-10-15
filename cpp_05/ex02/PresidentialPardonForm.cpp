#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string Target): AForm("PresidentialPardonForm", 25, 5), target(Target)
{
	std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	check_execution(executor);
	std::cout << target <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
}

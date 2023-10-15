#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string Target): AForm("RobotomyRequestForm", 72, 45), target(Target)
{
	std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	check_execution(executor);
	std::cout <<".........  * DRILLING NOISE * ........." << std::endl;
	if(rand() % 2 == 0)
		std::cout << target <<" has been robotomized." << std::endl;
	else
		std::cout << target <<" failed to be robotomized." << std::endl;
}

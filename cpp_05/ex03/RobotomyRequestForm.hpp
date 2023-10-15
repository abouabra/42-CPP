#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	std::string target;
public:
	RobotomyRequestForm(std::string Target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	void execute(Bureaucrat const & executor) const;
};

#endif
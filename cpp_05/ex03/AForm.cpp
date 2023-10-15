#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

AForm::AForm(): name("Default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string Name, int Grade_To_Sign, int Grade_To_Execute): name(Name), is_signed(false), grade_to_sign(Grade_To_Sign), grade_to_execute(Grade_To_Execute)
{
	if(Grade_To_Sign < 1 || Grade_To_Execute < 1)
		throw GradeTooHighException();
	if(Grade_To_Sign > 150 || Grade_To_Execute > 150)
		throw GradeTooLowException();
	std::cout << "graded constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
	
}

std::string AForm::getName() const
{
	return name;
}
int		AForm::Grade_To_Sign() const
{
	return grade_to_sign;
}

int		AForm::Grade_To_Execute() const
{
	return grade_to_execute;
}
bool		AForm::Is_Signed() const
{
	return is_signed;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= grade_to_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, AForm &Form)
{
	out <<"Form: " << Form.getName() << ", Grade To Sign: " << Form.Grade_To_Sign() << ", Grade To Execute: " << Form.Grade_To_Execute();
	return out;
}

void	AForm::check_execution(Bureaucrat const & executor) const
{
	if(executor.getGrade() > this->Grade_To_Execute())
		throw GradeTooLowException();
	if(!this->Is_Signed())
		throw NotSignedException();
}

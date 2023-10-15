#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <string>

Form::Form(): name("Default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string Name, int Grade_To_Sign, int Grade_To_Execute): name(Name), is_signed(false), grade_to_sign(Grade_To_Sign), grade_to_execute(Grade_To_Execute)
{
	if(Grade_To_Sign < 1 || Grade_To_Execute < 1)
		throw GradeTooHighException();
	if(Grade_To_Sign > 150 || Grade_To_Execute > 150)
		throw GradeTooLowException();
	std::cout << "graded constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Destructor called" << std::endl;
	
}

std::string Form::getName()
{
	return name;
}
int		Form::Grade_To_Sign()
{
	return grade_to_sign;
}

int		Form::Grade_To_Execute()
{
	return grade_to_execute;
}
bool		Form::Is_Signed()
{
	return is_signed;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= grade_to_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, Form &Form)
{
	out <<"Form: " << Form.getName() << ", Grade To Sign: " << Form.Grade_To_Sign() << ", Grade To Execute: " << Form.Grade_To_Execute();
	return out;
}
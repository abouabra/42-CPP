#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade): name(Name)
{
	if(Grade < 1)
		throw GradeTooHighException();
	if(Grade > 150)
		throw GradeTooLowException();
	
	grade = Grade;
	std::cout << "graded constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName()
{
	return name;
}
int		Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::increment()
{
	if(--grade < 1)
		throw GradeTooHighException();
}
void	Bureaucrat::decrement()
{
	if(++grade > 150)
		throw GradeTooLowException();
}
void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
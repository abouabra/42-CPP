#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(std::string Name, int Grade);
	~Bureaucrat();

	class GradeTooHighException: public std::exception
	{
		public:
			const char * what() const _NOEXCEPT
			{
				return "Bureaucrat Error: GradeTooHigh";
			}
	};
	class GradeTooLowException: public std::exception
	{
		public:
			const char * what() const _NOEXCEPT
			{
				return "Bureaucrat Error: GradeTooLow";
			}
	};
	std::string getName();
	int getGrade() const;

	void	increment();
	void	decrement();
	void	signForm(AForm &form);
	void	executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

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
	int		getGrade();

	void	increment();
	void	decrement();
	void	signForm(Form &form);
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif
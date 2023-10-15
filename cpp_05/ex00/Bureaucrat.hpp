#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
			const char * what() const throw ()
			{
				return "Error: GradeTooHigh";
			}
	};
	class GradeTooLowException: public std::exception
	{
		public:
			const char * what() const throw ()
			{
				return "Error: GradeTooLow";
			}
	};
	std::string getName();
	int		getGrade();

	void	increment();
	void	decrement();
};

std::ostream& operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif
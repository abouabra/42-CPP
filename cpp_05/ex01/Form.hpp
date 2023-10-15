#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;
class Form
{
private:
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_execute;
public:
	Form();
	Form(std::string Name, int Grade_To_Sign, int Grade_To_Execute);
	~Form();

	class GradeTooHighException: public std::exception
	{
		public:
			const char * what() const throw ()
			{
				return "Form Error: GradeTooHigh";
			}
	};
	class GradeTooLowException: public std::exception
	{
		public:
			const char * what() const throw ()
			{
				return "Form Error: GradeTooLow";
			}
	};
	std::string getName();
	int		Grade_To_Sign();
	int		Grade_To_Execute();
	bool		Is_Signed();
	void	beSigned(Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream &out, Form &form);

#endif
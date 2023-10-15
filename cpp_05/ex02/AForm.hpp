#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;
class AForm
{
private:
	const std::string name;
	bool is_signed;
	const int grade_to_sign;
	const int grade_to_execute;
public:
	AForm();
	AForm(std::string Name, int Grade_To_Sign, int Grade_To_Execute);
	virtual ~AForm();

	class GradeTooHighException: public std::exception
	{
		public:
			const char * what() const _NOEXCEPT
			{
				return "Form Error: GradeTooHigh";
			}
	};
	class GradeTooLowException: public std::exception
	{
		public:
			const char * what() const _NOEXCEPT
			{
				return "Form Error: GradeTooLow";
			}
	};
	class NotSignedException: public std::exception
	{
		public:
			const char * what() const _NOEXCEPT
			{
				return "Form Error: NotSigned";
			}
	};
	std::string getName() const;
	int		Grade_To_Sign() const;
	int		Grade_To_Execute() const;
	bool		Is_Signed() const;
	void	beSigned(Bureaucrat &bureaucrat);
	void	check_execution(Bureaucrat const & executor) const;

	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream &out, AForm &form);

#endif
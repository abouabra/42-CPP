#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	std::string target;
public:
	ShrubberyCreationForm(std::string Target);
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;

};

#endif
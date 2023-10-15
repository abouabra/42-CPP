#ifndef PRESEIDENTIALPARDONFORM_HPP
#define PRESEIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	std::string target;
public:
	PresidentialPardonForm(std::string Target);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};

#endif
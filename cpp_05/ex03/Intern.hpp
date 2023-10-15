#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
public:
	Intern();
	~Intern();
	AForm* makeForm(std::string form, std::string target);
	AForm *NewRobotomyRequestForm(std::string target);
	AForm *NewPresidentialPardonForm(std::string target);
	AForm *NewShrubberyCreationForm(std::string target);
	class FormDoesNotExistException: public std::exception
	{
		public:
			const char* what() const throw()
			{
				return ("Intern Error: Form does not exist");
			}
	};
};

#endif
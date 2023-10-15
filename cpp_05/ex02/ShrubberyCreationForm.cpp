#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target): AForm("ShrubberyCreationForm", 145, 137), target(Target)
{
	std::cout << "Default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	check_execution(executor);

	std::ofstream file;
	file.open(target + "_shrubbery");
	if (!file.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}

	file << "    oxoxoo    ooxoo          oxoxoo    ooxoo          oxoxoo    ooxoo     " << std::endl;
	file << "  ooxoxo oo  oxoxooo       ooxoxo oo  oxoxooo       ooxoxo oo  oxoxooo              " << std::endl;
	file << " oooo xxoxoo ooo ooox     oooo xxoxoo ooo ooox     oooo xxoxoo ooo ooox                " << std::endl;
	file << " oxo o oxoxo  xoxxoxo     oxo o oxoxo  xoxxoxo     oxo o oxoxo  xoxxoxo                " << std::endl;
	file << "  oxo xooxoooo o ooo       oxo xooxoooo o ooo       oxo xooxoooo o ooo              " << std::endl;
	file << "    ooo\\oo\\  /o/o            ooo\\oo\\  /o/o            ooo\\oo\\  /o/o        " << std::endl;
	file << "        \\  \\/ /                  \\  \\/ /                  \\  \\/ /    " << std::endl;
	file << "         |   /                    |   /                    |   /  " << std::endl;
	file << "         |  |                     |  |                     |  | " << std::endl;
	file << "         | D|                     | D|                     | D| " << std::endl;
	file << "         |  |                     |  |                     |  | " << std::endl;
	file << "         |  |                     |  |                     |  | " << std::endl;
	file << "  ______/____\\____         ______/____\\____         ______/____\\____          " << std::endl;

	file.close();
}

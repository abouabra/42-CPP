#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int	main()
{
	ClapTrap *FT = new FragTrap("Frag");
	ClapTrap *ST = new ClapTrap("Clap");

	ST->attack("taib");
	
	delete FT;
	delete ST;
	
	FragTrap obj("GG");
	obj.highFivesGuys();

	return 0;
}
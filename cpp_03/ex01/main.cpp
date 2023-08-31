#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap *CT = new ScavTrap("Scav");
	ClapTrap *ST = new ClapTrap("Clap");
	CT->attack("ayman ct");
	ST->attack("ayman st");

	delete CT;
	delete ST;
	return 0;
}
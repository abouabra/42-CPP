#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	DiamondTrap diamond("Diamond");
	
	std::cout << std::endl;
	std::cout << "Name: " << diamond.getName() << 
				"  Hp: " << diamond.getHP() <<
				"   Ep: " << diamond.getEP() <<
				" Ad: " << diamond.getAD() << std::endl;
	std::cout << std::endl;
	ClapTrap *D = new DiamondTrap("Diamond");
	D->attack("ME");
	delete D;
	return 0;
}
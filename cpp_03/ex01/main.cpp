#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap naruto;
	ScavTrap ayman("Ayman");

	std::cout << "Hp: " << naruto.getHP() << " Ep: " << naruto.getEP() << " Ad: " << naruto.getAD() << " Name: " << naruto.getName() << std::endl;
	std::cout << "Hp: " << ayman.getHP() << " Ep: " << ayman.getEP() << " Ad: " << ayman.getAD() << " Name: " << ayman.getName() << std::endl;

	naruto.attack("Ayman");
	ayman.guardGate();
	ayman.attack("naruto");
	ayman.takeDamage(99);

	std::cout << "Hp: " << naruto.getHP() << " Ep: " << naruto.getEP() << " Ad: " << naruto.getAD() << " Name: " << naruto.getName() << std::endl;
	std::cout << "Hp: " << ayman.getHP() << " Ep: " << ayman.getEP() << " Ad: " << ayman.getAD() << " Name: " << ayman.getName() << std::endl;

	return 0;
}
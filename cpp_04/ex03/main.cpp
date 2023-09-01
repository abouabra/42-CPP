
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{

    // ICharacter *character = new Character("ayman");

    // std::cout << character->getName() << std::endl;
    // Ice *ice = new Ice();
    // Cure *cure = new Cure();

    // // character->equip(ice);
    // // character->equip(cure);
    // character->equip(ice);
    // character->equip(cure);
    // character->use(0, *character);
    // character->use(1, *character);
    // character->use(2, *character);
    // character->use(3, *character);
    // character->unequip(0);
    // character->unequip(1);
    // character->unequip(2);
    // character->unequip(3);
    // character->equip(ice);
    // character->equip(cure);
    // character->use(1 , *character);
    // character->use(1, *character);
    // delete character;


    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}
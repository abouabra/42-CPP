
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main()
{
    Cat cat1;
    Cat cat2(cat1);

    std::cout << std::endl;

    Animal *animal[10];
    for(int i=0;i<10;i++)
    {
        if(i%2)
            animal[i] = new Cat();
        else
            animal[i] = new Dog();
        
    }
    std::cout << std::endl;

    for(int i=0;i<10;i++)
        std::cout << animal[i]->getType() << std::endl;

    std::cout << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    std::cout << std::endl;

    for(int i=0;i<10;i++)
        delete animal[i];
    return 0;
}
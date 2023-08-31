
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main()
{
    // Animal *animal = new Animal();
    // Animal *dog = new Dog();
    
    Cat cat1;
    Cat cat2(cat1);

    std::cout << std::endl;

    // cat1 = cat2;
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
        delete animal[i];
        
    // Animal 

    // std::cout << std::endl;
    
    
    // std::cout << "Type: " <<  animal->getType() << std::endl;
    // std::cout << "Type: " <<  dog->getType() << std::endl;
    // std::cout << "Type: " <<  cat->getType() << std::endl;
    
    std::cout << std::endl;

    // animal->makeSound();
    // dog->makeSound();
    // cat1->makeSound();
    
    // std::cout << std::endl;

    // delete animal;
    // delete dog;
    // delete cat1;
    return 0;
}
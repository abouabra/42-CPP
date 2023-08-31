
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    // Animal *animal = new Animal();
    Animal *dog = new Dog();
    Animal *cat = new Dog();
    
   
    std::cout << std::endl;
    
    
    // std::cout << "Type: " <<  animal->getType() << std::endl;
    std::cout << "Type: " <<  dog->getType() << std::endl;
    std::cout << "Type: " <<  cat->getType() << std::endl;
    
    std::cout << std::endl;

    // animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    
    std::cout << std::endl;

    // delete animal;
    delete dog;
    delete cat;
    return 0;
}
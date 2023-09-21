#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "               FIRST MAIN              " << std::endl;
        std::cout << "---------------------------------------" << std::endl;

        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;

        i->makeSound();
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "               SECOND MAIN             " << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

        std::cout << i->getType() << " " << std::endl;

        i->makeSound();
        meta->makeSound();

        delete meta;
        delete i;
    }
    {
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "               THIRD MAIN              " << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        
        Dog dog1;
        Dog dog2 (dog1);
        Dog dog3 = dog1;

        dog1.makeSound();
        dog2.makeSound();
        dog3.makeSound();

        Cat cat1;
        Cat cat2 (cat1);
        Cat cat3 = cat1;

        cat1.makeSound();
        cat2.makeSound();
        cat3.makeSound();
    }

    return (0);
}
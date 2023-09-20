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
        
        Dog const dog;

        dog.makeSound();

        return (0);
    }

    return (0);
}
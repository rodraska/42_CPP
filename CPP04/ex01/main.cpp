#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    Cat cat1;

    cat1.makeSound();
    cat1.NewIdea("caramelo com extra caramelo");
    cat1.NewIdea("BigMac with extra fries");
    cat1.NewIdea("Assaltar um sem-abrigo");
    cat1.ReadIdeas();

    return (0);
}
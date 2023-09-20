#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &src) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog & Dog::operator = (const Dog &src)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    this->type = src.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "woof woof" << std::endl;
}

std::string Dog::getType() const
{
    return (this->type);
}
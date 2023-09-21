#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &src)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal & Animal::operator = (const Animal &src)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->type = src.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal making a sound" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}
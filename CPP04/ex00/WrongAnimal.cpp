#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal &src)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    this->type = src.type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal making a sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
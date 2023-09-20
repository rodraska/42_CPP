#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat & WrongCat::operator = (const WrongCat &src)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->type = src.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->type);
}
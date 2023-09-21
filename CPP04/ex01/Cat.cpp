#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = src;
}

Cat & Cat::operator = (const Cat &src)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    this->type = src.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}

std::string Cat::getType() const
{
    return (this->type);
}

void Cat::NewIdea(std::string idea)
{
    this->brain->NewIdea(idea);
}

void Cat::ReadIdeas()
{
    this->brain->ReadIdeas();
}
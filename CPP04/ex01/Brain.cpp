#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
}

Brain & Brain::operator = (const Brain &src)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    for (int i = 0; i < 100 && !this->ideas[i].empty(); i++)
        this->ideas[i] = src.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

void Brain::NewIdea(std::string idea)
{
    int i = 0;
    while (i < 100 && !this->ideas[i].empty())
        i++;
    this->ideas[i] = idea;
}

void Brain::ReadIdeas()
{
    int i = -1;
    while (++i < 100 && !this->ideas[i].empty())
        std::cout << i << ": " <<  this->ideas[i] << std::endl;
}
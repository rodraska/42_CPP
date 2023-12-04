#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{   
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : _target(src.getTarget())
{
    *this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &src)
{
    if (this == &src)
        return (*this);
    this->_target = src.getTarget();
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    this->checkExecute(executor);
    
    srand(static_cast<unsigned int>(time(NULL)));
    int rand_nbr = rand() % 100 + 1;

    std::cout << "BRRRRR BRRRRR BRRRRR" << std::endl;
    if (rand_nbr <= 50)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "The robotomy on " << _target << " has failed"<< std::endl;
}
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 145, 137), _target("Default")
{   
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 145, 137), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : _target(src.getTarget())
{
    *this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &src)
{
    if (this == &src)
        return (*this);
    this->_target = src.getTarget();
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    this->checkExecute(executor);
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
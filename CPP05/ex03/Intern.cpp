#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    this->_forms[0] = "presidential pardon";
    this->_forms[1] = "robotomy request";
    this->_forms[2] = "shrubbery creation";
}

Intern::Intern(const Intern &src)
{
    *this = src;
}

Intern & Intern::operator = (const Intern &src)
{
    (void)src;
    return (*this);
}

Intern::~Intern()
{
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
    for (int i = 0; i < 3; i++)
    {
        if (this->_forms[i] == form_name)
        {
            std::cout << "Intern creates " << form_name << std::endl;
            switch (i)
            {
                case (0):
                    return (new PresidentialPardonForm(target));
                case (1):
                    return (new RobotomyRequestForm(target));
                case (2):
                    return (new ShrubberyCreationForm(target));
            }
        }
    }
    throw (UnknownForm());
}

const char* Intern::UnknownForm::what() const throw()
{
    return ("Unkown Form");
}
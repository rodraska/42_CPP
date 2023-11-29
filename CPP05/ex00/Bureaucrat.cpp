#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(1)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{ 
    if (grade < 1)
        throw (GradeTooHighException());
    else if (grade > 150)
        throw (GradeTooLowException());
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
    *this = src;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &src)
{
    if (this == &src)
        return (*this);
    this->_grade = src.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

const std::string Bureaucrat::getName() const
{
    return (this->_name);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade > 1)
        this->_grade--;
    else
        throw (GradeTooHighException());
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade < 150)
        this->_grade++;
    else
        throw (GradeTooLowException());
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade Too Low");
}

std::ostream & operator << (std::ostream &os, const Bureaucrat &obj)
{
    os << "Name: " << obj.getName() << ", Grade: " << obj.getGrade() << std::endl;
    return (os);
}
#include "AForm.hpp"

AForm::AForm() : _name("Default"), _sign(false), _sign_grade(1), _exec_grade(1)
{
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _sign(false)
{
    if (sign_grade < 1)
        throw (GradeTooHighException());
    else if (sign_grade > 150)
        throw (GradeTooLowException());
    else if (exec_grade < 1)
        throw (GradeTooHighException());
    else if (exec_grade > 150)
        throw (GradeTooLowException());
    this->_sign_grade = sign_grade;
    this->_exec_grade = exec_grade;
}

AForm::AForm(const AForm &src) : _name(src.getName())
{
    *this = src;
}

AForm & AForm::operator = (const AForm &src)
{
    if (this == &src)
        return (*this);
    this->_sign_grade = src.getSignGrade();
    this->_exec_grade = src.getExecGrade();
    return (*this);
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::getSignBool() const
{
    return (this->_sign);
}

int AForm::getSignGrade() const
{
    return (this->_sign_grade);
}

int AForm::getExecGrade() const
{
    return (this->_exec_grade);
}

void AForm::beSigned(Bureaucrat &obj)
{
    if (this->_sign_grade < obj.getGrade())
        throw (GradeTooLowException());
    this->_sign = true;
    obj.signForm(*this);
}

void    AForm::checkExecute(const Bureaucrat &executor) const
{
    if (this->getSignBool() == false)
        throw (AFormNotSigned());
    else if (this->getExecGrade() < executor.getGrade())
        throw (GradeTooLowException());
}

const char* AForm::AFormNotSigned::what() const throw()
{
    return ("AForm Not Signed");
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("AForm Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("AForm Grade Too Low");
}

std::ostream & operator << (std::ostream &os, const AForm &obj)
{
    os << "Name: " << obj.getName() << ", Sign: " << obj.getSignBool() << ", Grade Sign: " << obj.getSignGrade() << ", Exec Grade: " << obj.getExecGrade() << std::endl;
    return (os);
}
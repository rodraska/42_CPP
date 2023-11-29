#include "Form.hpp"

Form::Form() : _name("Default"), _sign(false), _sign_grade(1), _exec_grade(1)
{
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign(false)
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

Form::Form(const Form &src) : _name(src.getName())
{
    *this = src;
}

Form & Form::operator = (const Form &src)
{
    if (this == &src)
        return (*this);
    this->_sign_grade = src.getSignGrade();
    this->_exec_grade = src.getExecGrade();
    return (*this);
}

Form::~Form()
{
}

const std::string Form::getName() const
{
    return (this->_name);
}

bool Form::getSignBool() const
{
    return (this->_sign);
}

int Form::getSignGrade() const
{
    return (this->_sign_grade);
}

int Form::getExecGrade() const
{
    return (this->_exec_grade);
}

void Form::beSigned(Bureaucrat &obj)
{
    if (this->_sign_grade < obj.getGrade())
        throw (GradeTooLowException());
    this->_sign = true;
    obj.signForm(*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form Grade Too Low");
}

std::ostream & operator << (std::ostream &os, const Form &obj)
{
    os << "Name: " << obj.getName() << ", Sign: " << obj.getSignBool() << ", Grade Sign: " << obj.getSignGrade() << ", Exec Grade: " << obj.getExecGrade() << std::endl;
    return (os);
}
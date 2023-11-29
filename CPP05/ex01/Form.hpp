#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
    const std::string _name;
    bool _sign;
    int _sign_grade;
    int _exec_grade;

    public:
    Form();
    Form(std::string name, int sign_grade, int exec_grade);
    Form(const Form &src);
    Form & operator = (const Form &src);
    ~Form();

    const std::string   getName() const;
    bool                getSignBool() const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;
    void                beSigned(Bureaucrat &obj);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream & operator << (std::ostream &os, const Form &obj);

#endif
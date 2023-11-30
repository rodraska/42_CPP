#ifndef A_FORM_HPP
# define A_FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
    const std::string _name;
    bool _sign;
    int _sign_grade;
    int _exec_grade;

    public:
    AForm();
    AForm(std::string name, int sign_grade, int exec_grade);
    AForm(const AForm &src);
    AForm & operator = (const AForm &src);
    ~AForm();

    const std::string   getName() const;
    bool                getSignBool() const;
    int                 getSignGrade() const;
    int                 getExecGrade() const;
    void                beSigned(Bureaucrat &obj);
    void                checkExecute(const Bureaucrat &executor) const;
    virtual void        execute(const Bureaucrat &executor) const = 0;

    class AFormNotSigned : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

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

std::ostream & operator << (std::ostream &os, const AForm &obj);

#endif
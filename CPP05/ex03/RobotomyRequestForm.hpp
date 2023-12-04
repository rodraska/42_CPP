#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        RobotomyRequestForm & operator = (const RobotomyRequestForm &src);
        ~RobotomyRequestForm();

        std::string getTarget() const;
        void        execute(const Bureaucrat &executor) const;
};


#endif
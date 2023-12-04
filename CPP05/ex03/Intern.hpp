#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
    private:
        std::string _forms[3];
    public:
        Intern();
        Intern(const Intern &src);
        Intern & operator = (const Intern &src);
        ~Intern();

        AForm* makeForm(std::string form_name, std::string target);

        class UnknownForm : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif
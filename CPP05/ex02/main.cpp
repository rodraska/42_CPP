#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Bob signs and executes PresidentialPardonForm" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 1);
            PresidentialPardonForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Bob signs but cannot execute PresidentialPardonForm" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 140);
            PresidentialPardonForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Bob cannot sign form" << std::endl;
        std::cout << "--------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 150);
            PresidentialPardonForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Bob signs and executes RobotomyRequestForm" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 1);
            RobotomyRequestForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Bob signs but cannot execute RobotomyRequestForm" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 70);
            RobotomyRequestForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Bob cannot sign RobotomyRequestForm" << std::endl;
        std::cout << "--------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 150);
            RobotomyRequestForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "Bob signs and executes ShrubberyCreationForm" << std::endl;
        std::cout << "---------------------------------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 1);
            ShrubberyCreationForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << "---------------------------------------------------" << std::endl;
        std::cout << "Bob signs but cannot execute ShrubberyCreationForm" << std::endl;
        std::cout << "---------------------------------------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 20);
            ShrubberyCreationForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "Bob cannot sign ShrubberyCreationForm" << std::endl;
        std::cout << "--------------------" << std::endl;
        try
        {
            Bureaucrat Bob("Bob", 150);
            ShrubberyCreationForm form("Mohammed");
            form.beSigned(Bob);
            Bob.executeForm(form);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    return (0);
}
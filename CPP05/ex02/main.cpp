#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "PresidentialPardonForm #1" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "PresidentialPardonForm #2" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "PresidentialPardonForm #3" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "RobotomyRequestForm #1" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "RobotomyRequestForm #2" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "RobotomyRequestForm #3" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "ShrubberyCreationForm #1" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "ShrubberyCreationForm #2" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "ShrubberyCreationForm #3" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
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
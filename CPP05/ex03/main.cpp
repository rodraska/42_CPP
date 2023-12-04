#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "PresidentialPardonForm" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
        Intern random;
        AForm   *fff;
        Bureaucrat Pakulo("Pakulo Papito", 1);
        try
        {
            fff = random.makeForm("presidential pardon", "Juan");
            fff->beSigned(Pakulo);
            fff->execute(Pakulo);
            delete fff;
            
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "RobotomyRequestForm" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
        Intern random;
        AForm   *fff;
        Bureaucrat Pakulo("Pakulo Papito", 1);
        try
        {
            fff = random.makeForm("robotomy request", "Juan");
            fff->beSigned(Pakulo);
            fff->execute(Pakulo);
            delete fff;
            
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "ShrubberyCreationForm" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
        Intern random;
        AForm   *fff;
        Bureaucrat Pakulo("Pakulo Papito", 1);
        try
        {
            fff = random.makeForm("shrubbery creation", "Juan");
            fff->beSigned(Pakulo);
            fff->execute(Pakulo);
            delete fff;
            
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        std::cout << std::endl << "---------------------------------------------" << std::endl;
        std::cout << "Exception" << std::endl;
        std::cout << "---------------------------------------------" << std::endl << std::endl;
        Intern random;
        AForm   *fff;
        Bureaucrat Pakulo("Pakulo Papito", 1);
        try
        {
            fff = random.makeForm("random form", "Juan");
            fff->beSigned(Pakulo);
            fff->execute(Pakulo);
            delete fff;
            
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    return (0);
}
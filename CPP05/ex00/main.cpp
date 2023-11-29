#include "Bureaucrat.hpp"

int main()
{
    {
        try
        {
            Bureaucrat Rob("Roberto", 42);
            std::cout << Rob;
            Rob.incrementGrade();
            std::cout << Rob;
            Rob.decrementGrade();
            std::cout << Rob;
        }
        catch(std::exception &exc)
        {
            std::cerr << exc.what() << std::endl;
        }
    }
    {
        std::cout << "------------------------------------" << std::endl;
        try
        {
            Bureaucrat Ang("Angie", 1);
            std::cout << Ang;
            Ang.incrementGrade();
            std::cout << Ang;
            Ang.decrementGrade();
            std::cout << Ang;
        }
        catch(std::exception &exc)
        {
            std::cerr << exc.what() << std::endl;
        }
    }
    {
        std::cout << "------------------------------------" << std::endl;
        try
        {
            Bureaucrat Ger("Gervasio", 150);
            std::cout << Ger;
            Ger.decrementGrade();
            std::cout << Ger;
            Ger.incrementGrade();
            std::cout << Ger;
        }
        catch(std::exception &exc)
        {
            std::cerr << exc.what() << std::endl;
        }
    }
    return (0);
}
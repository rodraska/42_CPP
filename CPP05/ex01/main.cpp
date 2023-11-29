#include "Bureaucrat.hpp"

int main()
{
    {
        try
        {
            Bureaucrat Bob("Bob", 42);
            Form b12("b12", 42, 1);
            b12.beSigned(Bob);
            std::cout << b12;
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
            Bureaucrat Zed("Zed", 10);
            Form cx34("cx34", 9, 50);
            cx34.beSigned(Zed);
            std::cout << cx34;
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
            Form a76("a76", 151, 10);
            std::cout << a76;
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
            Form mno("mno", -5, 10);
            std::cout << mno;
        }
        catch(std::exception &exc)
        {
            std::cerr << exc.what() << std::endl;
        }
    }
    return (0);
}
#include "RPN.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 2)
        {
            RPN rpn(av[1]);
            rpn.Calc();
        }
        else
            throw (RPN::ErrorException());
    }
    catch (std::exception &exc)
    {
        std::cerr << exc.what() << std::endl;
    }     
}
#include "easyfind.hpp"

int main(void)
{
    {
        try
        {
            std::vector<int> vec;
            for (int i = 0; i < 5; i++)
            vec.push_back(i);
            ::easyfind(vec, 3);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        try
        {
            std::vector<int> vec;
            for (int i = 0; i < 5; i++)
            vec.push_back(i);
            ::easyfind(vec, 7);
        }
        catch (std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }

    return (0);
}
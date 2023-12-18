#include "Array.hpp"

int main(void)
{
    {
        Array<int> arr;
        std::cout << arr.size() << std::endl;
    }
    {
        Array<int> arr(5);
        for (int i = 0; i < 5; i++)
            arr[i] = i;
        try
        {
            std::cout << "arr[3]: " << arr[3] << std::endl;
        }
        catch(std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    {
        Array<int> arr(5);
        for (int i = 0; i < 5; i++)
            arr[i] = i;
        try
        {
            std::cout << "arr[8]: " << arr[8] << std::endl;
        }
        catch(std::exception &exc)
        {
            std::cout << exc.what() << std::endl;
        }
    }
    
}
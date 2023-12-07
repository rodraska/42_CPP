#include "iter.hpp"

int main(void)
{
    {
        int arr[4] = {1, 2, 3, 4};
        ::iter(arr, 4, &increase);
        for (int i = 0; i < 4; i++)
            std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
    }
    {
        char arr[] = "Hello";
        ::iter(arr, 5, &increase);
        for (int i = 0; i < 5; i++)
            std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
    }
    return (0);
}
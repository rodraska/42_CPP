#include "Serializer.hpp"

int main(void)
{
    int i = 42;
    int *ptr = &i;
    uintptr_t intptr = reinterpret_cast<uintptr_t>(ptr);

    std::cout << "i: " << i << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "intptr: " << intptr << std::endl;
}
#include "Serializer.hpp"

int main(void)
{
    int i;
    Data data_obj;
    uintptr_t int_ptr;
    Data *data_ptr;

    i = 42;
    data_obj.member = &i;

    int_ptr = Serializer::serialize(&data_obj);
    data_ptr = Serializer::deserialize(int_ptr);

    std::cout << "Original Pointer: " << &data_obj << std::endl;
    std::cout << "Final Pointer: " << data_ptr << std::endl;
    
    return (0);
}

/* int main(void)
{
    int i = 42;
    int *ptr = &i;
    uintptr_t intptr = reinterpret_cast<uintptr_t>(ptr);
    Data* data_ptr = reinterpret_cast<Data*>(intptr);

    std::cout << "i: " << i << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "intptr: " << intptr << std::endl;
    std::cout << "data_ptr: " << data_ptr << std::endl;
} */
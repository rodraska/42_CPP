#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp" 

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer &src);
        Serializer & operator = (const Serializer &src);
        ~Serializer();

        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
};



#endif
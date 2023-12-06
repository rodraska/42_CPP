#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
    *this = src;
}

Serializer & Serializer::operator = (const Serializer &src)
{
    (void)src;
    return (*this);
}

Serializer::~Serializer()
{
}

uintptr_t Serializer::serialize(Data *ptr)
{
}

Data* Serializer::deserialize(uintptr_t raw)
{
}
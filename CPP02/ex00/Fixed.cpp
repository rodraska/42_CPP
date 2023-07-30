#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    this->value = 0;
}

Fixed::Fixed(const Fixed &f)
{
    std::cout << "Copy constructor called\n";
    this->setRawBits(f.getRawBits());
}

Fixed & Fixed::operator = (const Fixed &f)
{
    std::cout << "Copy assignment operator called\n";
    this->setRawBits(f.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called\n";
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
    //std::cout << "setRawBits member function called\n";
}
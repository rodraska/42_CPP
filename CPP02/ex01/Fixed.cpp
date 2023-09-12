#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called" << std::endl;;
    this->setRawBits(value << this->frac_bits);
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called" << std::endl;;
    this->setRawBits(roundf(value * pow(2, this->frac_bits)));
}

Fixed::Fixed(Fixed const &f)
{
    std::cout << "Copy constructor called" << std::endl;;
    this->setRawBits(f.getRawBits());
}

Fixed & Fixed::operator = (const Fixed & f)
{
    std::cout << "Copy assignment operator called" << std::endl;;
    this->setRawBits(f.getRawBits());
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;;
}

int Fixed::getRawBits(void) const
{
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)(this->getRawBits() / pow(2, this->frac_bits));
}

int Fixed::toInt(void) const
{
    return (int)(this->getRawBits() >> this->frac_bits);
}

std::ostream & operator << (std::ostream &os, Fixed const &f)
{
    os << f.toFloat();
    return (os);
}
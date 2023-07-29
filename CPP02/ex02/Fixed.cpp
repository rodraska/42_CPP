#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called\n";
    this->value = 0;
}

Fixed::Fixed(int const value)
{
    std::cout << "Int constructor called\n";
    this->setRawBits(value << this->frac_bits);
}

Fixed::Fixed(float const value)
{
    std::cout << "Float constructor called\n";
    this->setRawBits(roundf(value * pow(2, this->frac_bits)));
}

Fixed::Fixed(Fixed const &f)
{
    std::cout << "Copy constructor called\n";
    this->setRawBits(f.getRawBits());
}

Fixed & Fixed::operator = (const Fixed & f)
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
    //std::cout << "getRawBits member function called\n";
    return (this->value);
}

void Fixed::setRawBits(int const raw)
{
    this->value = raw;
    //std::cout << "setRawBits member function called\n";
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

bool Fixed::operator > (const Fixed &f)
{
    return (this->value > f.value);
}

bool Fixed::operator < (const Fixed &f)
{
    return (this->value < f.value);
}

bool Fixed::operator >= (const Fixed &f)
{
    return (this->value >= f.value);
}

bool Fixed::operator <= (const Fixed &f)
{
    return (this->value <= f.value);
}

bool Fixed::operator != (const Fixed &f)
{
    return (this->value != f.value);
}

Fixed Fixed::operator + (const Fixed &f)
{
    return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed Fixed::operator - (const Fixed &f)
{
    return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed Fixed::operator * (const Fixed &f)
{
    return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed Fixed::operator / (const Fixed &f)
{
    return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed & Fixed::min(Fixed &f1, Fixed &f2)
{
    if (f1.value < f2.value)
        return (f1);
    return (f2);
}

const Fixed & Fixed::min(const Fixed &f1, const Fixed &f2)
{
    if (f1.value < f2.value)
        return (f1);
    return (f2);
}

Fixed & Fixed::max(Fixed &f1, Fixed &f2)
{
    if (f1.value > f2.value)
        return (f1);
    return (f2);
}

const Fixed & Fixed::max(const Fixed &f1, const Fixed &f2)
{
    if (f1.value > f2.value)
        return (f1);
    return (f2);
}

Fixed & Fixed::operator ++ ()
{
    this->value++;
    return (*this);
}

Fixed & Fixed::operator -- ()
{
    this->value--;
    return (*this);
}

Fixed Fixed::operator ++ (int num)
{
    (void)num;
    Fixed f(this->toFloat());
    this->value++;
    return (f);
}

Fixed Fixed::operator -- (int num)
{
    (void)num;
    Fixed f(this->toFloat());
    this->value--;
    return (f);
}
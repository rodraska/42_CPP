#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
    private:
        int value;
        static const int frac_bits;
    public:
        Fixed();
        Fixed(int const value);
        Fixed(float const value);
        Fixed(Fixed const &f);
        Fixed & operator = (const Fixed &f);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream & operator << (std::ostream &os, Fixed const &f);

#endif
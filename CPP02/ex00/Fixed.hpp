#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
    private:
        int value;
        static const int frac_bits;
    public:
        Fixed();
        Fixed(Fixed &f);
        Fixed & operator = (const Fixed &f);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif
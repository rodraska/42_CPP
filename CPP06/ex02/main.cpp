#include "Base.hpp"

int main(void)
{
    Base* base_ptr = Base::generate();
    Base::identify(base_ptr);
}
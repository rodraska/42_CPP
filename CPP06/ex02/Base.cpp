#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout << "Base Destructor Called" << std::endl;
}

Base* Base::generate()
{
    srand(static_cast<unsigned int>(time(NULL)));
    int rand_nbr = rand() % 3 + 1;

    switch (rand_nbr)
    {
        case (1):
            return (new A());
        case (2):
            return (new B());
        case (3):
            return (new C());
    }
    return (NULL);
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C" << std::endl;
    else
        std::cout << "None of A,B or C" << std::endl;
}

void Base::identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        std::cout << "Class A" << std::endl;
        (void)a;
    }
    catch(std::exception &exc)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "Class B" << std::endl;
            (void)b;
        }
        catch(std::exception &exc)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "Class C" << std::endl;
                (void)c;
            }
            catch(std::exception &exc)
            {
                std::cout << "None of A,B or C" << std::endl;
            }
        }
    }
}
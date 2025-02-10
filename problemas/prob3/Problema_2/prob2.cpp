#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "vector.hpp"

int main(void)
{
    AyED::vector v1(100);

    v1.init_random(-100, 100);

    std::cout << "Vector v1" << std::endl;
    std::cout << v1 << std::endl;
    std::cout << std::endl;

    v1.sort();

    std::cout << "Vector v1 ordenado" << std::endl;
    std::cout << v1 << std::endl;
    std::cout << std::endl;

    return 0;
}

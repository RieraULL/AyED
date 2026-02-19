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

    AyED::vector v2(v1);

    v2[50] = -50.0;

    std::cout << "Vector v2" << std::endl;
    std::cout << v2 << std::endl;
    std::cout << std::endl;

    size_t pos{0};
    const bool found{v2.find_first(-50.0, 0.01, pos)};

    if (found)
        std::cout << "El valor 10 se encuentra en la posición " << pos << std::endl;
    else
        std::cout << "El valor 10 no se encuentra en el vector" << std::endl;


    v2.sort();

    std::cout << "Vector v2 ordenado" << std::endl;
    std::cout << v2 << std::endl;
    std::cout << std::endl;

    const bool found_sorted{v2.find_first_sorted(-50.0, 0.01, pos)};

    if (found_sorted)
        std::cout << "El valor 10 se encuentra en la posición " << pos << std::endl;
    else
        std::cout << "El valor 10 no se encuentra en el vector" << std::endl;


    return 0;
}

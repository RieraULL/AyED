#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "vector.hpp"
#include "i_vector.hpp"



int main(void)
{
    const double precision{1e-3};

    AyED::vector v1;

    std::cout << "Leyendo vector v1" << std::endl;
    std::cin >> v1;
    std::cout << v1 << std::endl;
    std::cout << std::endl;

    AyED::vector v2;

    std::cout << "Leyendo vector v2" << std::endl;
    std::cin >> v2;
    std::cout << v2 << std::endl;
    std::cout << std::endl;

    std::cout << "Producto escalar: ";
    std::cout << std::setw(MAX_WIDE) << std::fixed << std::setprecision(MAX_PRECISION) << v1 * v2 << std::endl;
    std::cout << std::endl;

    std::cout << "Los vectores v1 y v2";
    if (v1.perpendicular(v2, precision))
        std::cout << " son perpendiculares" << std::endl;
    else
        std::cout << " no son perpendiculares" << std::endl;
    std::cout << std::endl;

    AyED::vector v3;

    std::cout << "Leyendo vector v3" << std::endl;
    std::cin >> v3;
    std::cout << v3 << std::endl;
    std::cout << std::endl;

    AyED::vector v4;

    std::cout << "Leyendo vector v4" << std::endl;
    std::cin >> v4;
    std::cout << v4 << std::endl;
    std::cout << std::endl;

    std::cout << "Producto escalar: ";
    std::cout << std::setw(MAX_WIDE) << std::fixed << std::setprecision(MAX_PRECISION) << v3 * v4 << std::endl;
    std::cout << std::endl;

    std::cout << "Los vectores v3 y v4";
    if (v3.perpendicular(v4, precision))
        std::cout << " son perpendiculares" << std::endl;
    else
        std::cout << " no son perpendiculares" << std::endl;
    std::cout << std::endl;

    const AyED::vector v5{v1};
    v3 = v5;

    std::cout << "Vector v5" << std::endl;
    std::cout << v5 << std::endl;
    std::cout << std::endl;

    std::cout << "Vector v3" << std::endl;
    std::cout << v3 << std::endl;
    std::cout << std::endl;

    std::cout << "Vector iv1" << std::endl;
    AyED::i_vector iv1{-3, 5};

    for (int i{-3}; i <= 5; ++i)
        iv1[i] = i + 0.5;

    std::cout << iv1 << std::endl;

    return 0;
}

/* Compilar: g++ -g main.cpp vector.cpp -o vector */

#include <iostream>
#include <iomanip>

#include "vector.hpp"

#define VECTOR_SZ 10

int main(void)
{
    const int sz = VECTOR_SZ;

    AyED::vector v(sz);
    AyED::vector w;

    w.resize(sz);

    double val = 5.0;

    for (int i{0}; i < sz; i++)
    {

        v.at(i) = val;

        val += 0.05;

        w[i] = val;
    }

    v.write(std::cout);
    std::cout << std::endl;
    std::cout << w << std::endl;
}

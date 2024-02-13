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

    for(int i = 0; i < sz; i++){
        
        v.at(i) = val;
        
        val += 0.05;
        
        w[i] = val;
    }
    
    v.write(std::cout); std::cout << std::endl;
    std::cout << w << std::endl;

    const int ocur1 = v.ocurrencias(5.2, 0.001);
    const int ocur2 = v.ocurrencias(5.2, 0.100);
    const int ocur3 = v.ocurrencias(5.2, 0.500);
    
    std::cout << std::setw(5) << ocur1 << std::setw(5) << ocur2 << std::setw(5) << ocur3 << std::endl;
    
    std::cout << v * w << std::endl;
    std::cout << v.scalprod(w) << std::endl;
}

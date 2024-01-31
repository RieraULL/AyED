#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>

#include "function_eval.hpp"

double poly_2(double x)
{
    return x * x + 2 * x + 1;
}

double cuadrado(double x)
{
    return x * x;
}

int main(void)
{
    {
        AyED::function_evaluation f(-2 * M_1_PI, 2 * M_PI, 1E-3, sin);

        std::ofstream output_file("sin.dat");
        output_file << f;
        output_file.close();
    }

    {
        AyED::function_evaluation f(0, 100, 1E-3, poly_2);

        std::ofstream output_file("poly_2.dat");
        output_file << f;
        output_file.close();
    }

    {
        AyED::function_evaluation f(-100, 100, 1E-3, fabs);

        std::ofstream output_file("abs.dat");
        output_file << f;
        output_file.close();
    }

    {
        AyED::function_evaluation f(-100, 100, 1E-3, cuadrado);

        std::ofstream output_file("cuadrado.dat");
        output_file << f;
        output_file.close();
    }    

    return 0;
}
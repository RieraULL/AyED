#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>

#include "function_eval.hpp"

double cuadrado(double x)
{
    return x * x;
}

double absoluto(double x)
{
    return fabs(x);
}

int main(void)
{
    AyED::function_evaluation f(-2 * M_1_PI, 2 * M_PI, 1E-3);

    f.evaluate(sin);

    {
        std::ofstream output_file("sin.dat");
        f.write(output_file);
        output_file.close();
    }

    f.evaluate(cuadrado);

    {
        std::ofstream output_file("cua.dat");
        f.write(output_file);
        output_file.close();
    }

    f.evaluate(absoluto);

    {
        std::ofstream output_file("abs.dat");
        f.write(output_file);
        output_file.close();
    }

    return 0;
}
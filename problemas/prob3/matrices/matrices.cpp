#include "matrix_h.hpp"
#include <iostream>
#include <iomanip>


int main(void)
{
    AyED::matrix_h A(5, 5);

    A.init_random(1);

    A.write(std::cout);
    std::cout << std::endl;

    std::cout << "Suma total                        : " << std::setw(5) << A.suma_total() << std::endl;
    std::cout << "Suma diagonal principal           : " << std::setw(5) << A.suma_diag_p() << std::endl;
    std::cout << "Suma diagnoal secundaria          : " << std::setw(5) << A.suma_diag_s() << std::endl;
    std::cout << "Suma triangular inf. con diagonal : " << std::setw(5) << A.suma_tria_inf_diag() << std::endl;
    std::cout << "Suma triangular inf. sin diagonal : " << std::setw(5) << A.suma_tria_inf() << std::endl;
    std::cout << "Suma triangular sup. con diagonal : " << std::setw(5) << A.suma_tria_sup_diag() << std::endl;
    std::cout << "Suma triangular sup. sin diagonal : " << std::setw(5) << A.suma_tria_sup() << std::endl;
    std::cout << std::endl;

    AyED::matrix_h B(3, 4);
    AyED::matrix_h C(3, 4);
    AyED::matrix_h D(3, 4);

    B.init_random(2);
    C.init_random(3);

    D.suma(B, C);

    std::cout << "B" << std::endl;
    B.write(std::cout);
    std::cout << std::endl;
    std::cout << "C" << std::endl;
    C.write(std::cout);
    std::cout << std::endl;
    std::cout << "D = B + C" << std::endl;
    D.write(std::cout);
    std::cout << std::endl;

    AyED::matrix_h E(3, 4);
    AyED::matrix_h F(4, 5);
    AyED::matrix_h G(3, 5);

    E.init_random(2);
    F.init_random(3);

    G.producto(E, F);

    std::cout << "E" << std::endl;
    E.write(std::cout);
    std::cout << std::endl;
    std::cout << "F" << std::endl;
    F.write(std::cout);
    std::cout << std::endl;
    std::cout << "G = E x F" << std::endl;
    G.write(std::cout);
    std::cout << std::endl;

    return 0;
}
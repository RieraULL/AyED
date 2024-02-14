// Compila: g++ -g -o matrices matrices.cpp

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cassert>

#define MAX_VAL 2

namespace AyED
{

    class vector
    {
    public:
        vector(int sz) : v_(NULL),
                         sz_(sz)
        {
            build();
        }

        ~vector(void)
        {
            destroy();
        }

        int get_sz(void) const
        {
            return sz_;
        }

        int &at(int i)
        {
            assert(i >= 0);
            assert(i < sz_);

            return v_[i];
        }

        int at(int i) const
        {
            assert(i >= 0);
            assert(i < sz_);

            return v_[i];
        }

    private:
        void build(void)
        {
            v_ = new int[sz_];
        }

        void destroy(void)
        {
            if (v_ != NULL)
                delete[] v_;
        }

    private:
        int *v_;
        int sz_;
    };

    class matrix
    {

    public:
        matrix(int m, int n) : v_(m * n),
                               m_(m),
                               n_(n) {}

        ~matrix(void) {}

        int get_m(void) const
        {
            return m_;
        }

        int get_n(void) const
        {
            return n_;
        }

        int &at(int i, int j)
        {
            return v_.at(pos(i, j));
        }

        int at(int i, int j) const
        {
            return v_.at(pos(i, j));
        }

        void write(std::ostream &os) const
        {
            for (int i = 1; i <= get_m(); i++)
            {
                for (int j = 1; j <= get_n(); j++)
                    os << std::setw(4) << at(i, j) << " ";

                os << std::endl;
            }
        }

        void init_random(int seed)
        {
            srand(seed);

            for (int i = 1; i <= get_m(); i++)
                for (int j = 1; j <= get_n(); j++)
                    at(i, j) = rand() % MAX_VAL;
        }

        int suma_total(void) const
        {
            int sum = 0;

            for (int i = 1; i <= get_m(); i++)
                for (int j = 1; j <= get_n(); j++)
                    sum += at(i, j);

            return sum;
        }

        int suma_ind_par(void) const
        {
            int sum = 0;

            for (int i = 1; i <= get_m(); i++)
                for (int j = 1; j <= get_n(); j++)
                    if ((i + j) % 2 == 0)
                        sum += at(i, j);

            return sum;
        }

        int suma_diag_p(void) const
        {
            assert(get_m() == get_n());

            int sum = 0;

            for (int i = 1; i <= get_m(); i++)
                sum += at(i, i);

            return sum;
        }

        int suma_diag_s(void) const
        {
            assert(get_m() == get_n());

            int sum = 0;

            for (int i = 1; i <= get_m(); i++)
                sum += at(i, get_n() - i + 1);

            return sum;
        }

        int suma_tria_inf_diag(void) const
        {
            assert(get_m() == get_n());

            int sum = 0;

            for (int i = 1; i <= get_m(); i++)
                for (int j = 1; j <= i; j++)
                    sum += at(i, j);

            return sum;
        }

        int suma_tria_inf(void) const
        {
            assert(get_m() == get_n());

            int sum = 0;

            for (int i = 2; i <= get_m(); i++)
                for (int j = 1; j < i; j++)
                    sum += at(i, j);

            return sum;
        }

        int suma_tria_sup_diag(void) const
        {
            assert(get_m() == get_n());

            int sum = 0;

            for (int i = 1; i <= get_m(); i++)
                for (int j = i; j <= get_n(); j++)
                    sum += at(i, j);

            return sum;
        }

        int suma_tria_sup(void) const
        {
            assert(get_m() == get_n());

            int sum = 0;

            for (int i = 1; i < get_m(); i++)
                for (int j = i + 1; j <= get_n(); j++)
                    sum += at(i, j);

            return sum;
        }

        void suma(const matrix &A, const matrix &B)
        {
            assert(get_m() == A.get_m());
            assert(get_m() == B.get_m());
            assert(get_n() == A.get_n());
            assert(get_n() == B.get_n());

            for (int i = 1; i <= get_m(); i++)
                for (int j = 1; j <= get_n(); j++)
                    at(i, j) = A.at(i, j) + B.at(i, j);
        }

        void producto(const matrix &A, const matrix &B)
        {
            assert(get_m() == A.get_m());
            assert(get_n() == B.get_n());
            assert(A.get_n() == B.get_m());

            for (int i = 1; i <= get_m(); i++)
                for (int j = 1; j <= get_n(); j++)
                {

                    at(i, j) = 0;

                    for (int k = 1; k <= A.get_n(); k++)
                        at(i, j) += A.at(i, k) * B.at(k, j);
                }
        }

    private:
        int pos(int i, int j) const
        {
            assert(i >= 1);
            assert(j >= 1);
            assert(i <= get_m());
            assert(j <= get_n());

            return (i - 1) * n_ + j - 1;
        }

    private:
        vector v_;
        int m_;
        int n_;
    };
}

int main(void)
{
    AyED::matrix A(5, 5);

    A.init_random(1);

    A.write(std::cout);

    std::cout << "Suma total                        : " << std::setw(5) << A.suma_total() << std::endl;
    std::cout << "Suma índice par                   : " << std::setw(5) << A.suma_ind_par() << std::endl;
    std::cout << "Suma diagonal principal           : " << std::setw(5) << A.suma_diag_p() << std::endl;
    std::cout << "Suma diagnoal secundaria          : " << std::setw(5) << A.suma_diag_s() << std::endl;
    std::cout << "Suma triangular inf. con diagonal : " << std::setw(5) << A.suma_tria_inf_diag() << std::endl;
    std::cout << "Suma triangular inf. sin diagonal : " << std::setw(5) << A.suma_tria_inf() << std::endl;
    std::cout << "Suma triangular sup. con diagonal : " << std::setw(5) << A.suma_tria_sup_diag() << std::endl;
    std::cout << "Suma triangular sup. sin diagonal : " << std::setw(5) << A.suma_tria_sup() << std::endl;
    std::cout << std::endl;

    AyED::matrix B(3, 4);
    AyED::matrix C(3, 4);
    AyED::matrix D(3, 4);

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

    AyED::matrix E(3, 4);
    AyED::matrix F(4, 5);
    AyED::matrix G(3, 5);

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
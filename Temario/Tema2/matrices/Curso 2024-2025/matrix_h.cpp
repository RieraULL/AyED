#include "matrix_h.hpp"

#include <cassert>
#include <iostream>
#include <iomanip>

#define MAX_VAL 10

namespace AyED
{
    matrix_h::matrix_h(size_t m, size_t n) : vector(m * n),
                                             m_(m),
                                             n_(n) {}

    matrix_h::~matrix_h(void) {}

    void matrix_h::resize(size_t m, size_t n)
    {
        m_ = m;
        n_ = n;

        vector::resize(m * n);
    }

    size_t matrix_h::pos_(const size_t i, const size_t j) const
    {
        assert(i >= 1 && i <= get_m());
        assert(j >= 1 && j <= get_n());

        return (i - 1) * get_n() + j - 1;
    }

    size_t matrix_h::get_m(void) const
    {
        return m_;
    }

    size_t matrix_h::get_n(void) const
    {
        return n_;
    }

    double &matrix_h::at(const size_t i, const size_t j)
    {
        return vector::at(pos_(i, j));
    }

    double matrix_h::at(const size_t i, const size_t j) const
    {
        return vector::at(pos_(i, j));
    }

    double matrix_h::operator()(const size_t i, const size_t j) const
    {
        return at(i, j);
    }

    double &matrix_h::operator()(const size_t i, const size_t j)
    {
        return at(i, j);
    }

    std::ostream &matrix_h::write(std::ostream &os) const
    {
        for (size_t i{1}; i <= get_m(); i++)
        {
            for (size_t j{1}; j <= get_n(); j++)
                os << std::setw(6) << std::fixed << std::setprecision(1) << at(i, j) << " ";

            os << std::endl;
        }

        return os;
    }

    void matrix_h::init_random(int seed)
    {
        srand(seed);

        for (size_t i{1}; i <= get_m(); i++)
            for (size_t j{1}; j <= get_n(); j++)
                at(i, j) = rand() % MAX_VAL;
    }

    double matrix_h::suma_total(void) const
    {
        double sum{0};

        for (size_t i{1}; i <= get_m(); i++)
            for (size_t j{1}; j <= get_n(); j++)
                sum += at(i, j);

        return sum;
    }

    double matrix_h::suma_diag_p(void) const
    {
        assert(get_m() == get_n());

        int sum{0};

        for (size_t i{1}; i <= get_m(); i++)
            sum += at(i, i);

        return sum;
    }

    double matrix_h::suma_diag_s(void) const
    {
        assert(get_m() == get_n());

        int sum{0};

        for (size_t i{1}; i <= get_m(); i++)
            sum += at(i, get_n() - i + 1);

        return sum;
    }

    double matrix_h::suma_tria_inf_diag(void) const
    {
        assert(get_m() == get_n());

        int sum{0};

        for (size_t i{1}; i <= get_m(); i++)
            for (size_t j{1}; j <= i; j++)
                sum += at(i, j);

        return sum;
    }

    double matrix_h::suma_tria_inf(void) const
    {
        assert(get_m() == get_n());

        int sum{0};

        for (size_t i = 2; i <= get_m(); i++)
            for (size_t j{1}; j < i; j++)
                sum += at(i, j);

        return sum;
    }

    double matrix_h::suma_tria_sup_diag(void) const
    {
        assert(get_m() == get_n());

        int sum{0};

        for (size_t i{1}; i <= get_m(); i++)
            for (size_t j = i; j <= get_n(); j++)
                sum += at(i, j);

        return sum;
    }

    double matrix_h::suma_tria_sup(void) const
    {
        assert(get_m() == get_n());

        int sum{0};

        for (size_t i{1}; i < get_m(); i++)
            for (size_t j{i + 1}; j <= get_n(); j++)
                sum += at(i, j);

        return sum;
    }

    void matrix_h::traspuesta_cuadrada(void)
    {
        assert(get_m() == get_n());

        for (size_t i{1}; i <= get_m(); i++)
            for (size_t j{i + 1}; j <= get_n(); j++)
            {
                double aux{at(i, j)};
                at(i, j) = at(j, i);
                at(j, i) = aux;
            }
    }

    void matrix_h::suma(const matrix_h &A, const matrix_h &B)
    {
        assert(get_m() == A.get_m());
        assert(get_m() == B.get_m());
        assert(get_n() == A.get_n());
        assert(get_n() == B.get_n());

        for (size_t i{1}; i <= get_m(); i++)
            for (size_t j{1}; j <= get_n(); j++)
                at(i, j) = A.at(i, j) + B.at(i, j);
    }

    void matrix_h::producto(const matrix_h &A, const matrix_h &B)
    {
        assert(get_m() == A.get_m());
        assert(get_n() == B.get_n());
        assert(A.get_n() == B.get_m());

        for (size_t i{1}; i <= get_m(); i++)
            for (size_t j{1}; j <= get_n(); j++)
            {

                at(i, j) = 0;

                for (size_t k{1}; k <= A.get_n(); k++)
                    at(i, j) += A.at(i, k) * B.at(k, j);
            }
    }
}
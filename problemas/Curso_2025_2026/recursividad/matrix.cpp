#include "matrix.hpp"

#include <cassert>
#include <iostream>
#include <iomanip>

#define MAX_VAL 10

namespace AyED
{
    matrix::matrix(size_t m, size_t n) : vector(m * n),
                                             m_(m),
                                             n_(n) {}

    matrix::~matrix(void) {}

    void matrix::resize(size_t m, size_t n)
    {
        m_ = m;
        n_ = n;

        vector::resize(m * n);
    }

    size_t matrix::pos_(const size_t i, const size_t j) const
    {
        assert(i >= 1 && i <= get_m());
        assert(j >= 1 && j <= get_n());

        return (i - 1) * get_n() + j - 1;
    }

    size_t matrix::get_m(void) const
    {
        return m_;
    }

    size_t matrix::get_n(void) const
    {
        return n_;
    }

    int &matrix::at(const size_t i, const size_t j)
    {
        return vector::at(pos_(i, j));
    }

    int matrix::at(const size_t i, const size_t j) const
    {
        return vector::at(pos_(i, j));
    }

    int matrix::operator()(const size_t i, const size_t j) const
    {
        return at(i, j);
    }

    int &matrix::operator()(const size_t i, const size_t j)
    {
        return at(i, j);
    }

    std::ostream &matrix::write(std::ostream &os) const
    {
        for (size_t i{1}; i <= get_m(); i++)
        {
            for (size_t j{1}; j <= get_n(); j++)
                os << std::setw(6) << std::fixed << std::setprecision(1) << at(i, j) << " ";

            os << std::endl;
        }

        return os;
    }

}
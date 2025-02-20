#pragma once

#include <iostream>

#include "vector.hpp"

namespace AyED
{
    class i_vector : private vector
    {
    public:
        i_vector(int a, int b);
        ~i_vector(void);

        double at(const int pos) const;
        double &at(const int pos);

        double operator[](const int pos) const;
        double &operator[](const int pos);

        std::ostream &write(std::ostream &os) const;

    private:
        int a_;
        int b_;
    };
}

std::ostream &operator<<(std::ostream &os, const AyED::i_vector &v);

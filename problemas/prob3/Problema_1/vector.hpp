#pragma once

#include <iostream>

#define MAX_WIDE 6
#define MAX_PRECISION 2

namespace AyED
{

    class vector
    {
    public:
        vector(void);
        vector(size_t sz);
        ~vector(void);

        size_t size(void) const;

        double at(const size_t pos) const;
        double &at(const size_t pos);

        double operator[](const size_t pos) const;
        double &operator[](const size_t pos);

        double scalar_product(const vector &v) const;

        bool perpendicular(const vector &v, const double precision = 1E-3) const;

        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &is);

    private:
        void crea_vector_(void);
        void destruye_vector_(void);

    private:
        double *v_;
        size_t sz_;
    };
}

std::ostream &operator<<(std::ostream &os, const AyED::vector &v);

std::istream &operator>>(std::istream &is, AyED::vector &v);

double operator*(const AyED::vector &v1, const AyED::vector &v2);

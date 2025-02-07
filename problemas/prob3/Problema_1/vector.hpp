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

        const double &at(size_t pos) const;
        double &at(size_t pos);

        const double &operator[](size_t pos) const;
        double &operator[](size_t pos);

        double scalar_product(const vector &v) const;

        bool perpendicular(const double precision, const vector &v) const;

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

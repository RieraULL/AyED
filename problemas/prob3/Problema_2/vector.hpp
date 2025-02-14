#pragma once

#include <iostream>

#define MAX_WIDE 6
#define MAX_PRECISION 2

namespace AyED
{

    class vector
    {
    public:
        vector(size_t sz);
        vector(const vector &v);
        ~vector(void);

        void init_random(const double min, const double max);
        std::ostream &write(std::ostream &os) const;
        vector &operator=(const vector &v);

        size_t size(void) const;
        double at(const size_t pos) const;
        double &at(const size_t pos);
        double operator[](const size_t pos) const;
        double &operator[](const size_t pos);

        void sort(void);
        bool sequential_search(const double val, const double eps, size_t &pos) const;
        bool binary_search(const double val, const double eps, size_t &pos) const;
        size_t count(const double val, const double eps) const;

    private:
        void crea_vector_(void);
        void destruye_vector_(void);

        size_t smaller_inx_(const size_t a, const size_t b) const;
        void swap_(const size_t a, const size_t b);

    private:
        double *v_;
        size_t sz_;
    };
}

std::ostream &operator<<(std::ostream &os, const AyED::vector &v);

double operator*(const AyED::vector &v1, const AyED::vector &v2);

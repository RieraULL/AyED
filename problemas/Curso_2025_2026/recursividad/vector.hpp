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
        vector(const vector &v);
        ~vector(void);

        void resize(size_t sz);

        size_t size(void) const;

        int at(const size_t pos) const;
        int &at(const size_t pos);

        int operator[](const size_t pos) const;
        int &operator[](const size_t pos);

        vector &operator=(const vector &v);

        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &is);

    private:
        void crea_vector_(void);
        void destruye_vector_(void);

    private:
        int *v_;
        size_t sz_;
    };
}

std::ostream &operator<<(std::ostream &os, const AyED::vector &v);

std::istream &operator>>(std::istream &is, AyED::vector &v);


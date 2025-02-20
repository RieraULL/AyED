#include "vector.hpp"

#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cassert>

namespace AyED
{

    vector::vector(void) : v_(NULL),
                           sz_(0) {}

    vector::vector(size_t sz) : v_(NULL),
                                sz_(sz)
    {
        crea_vector_();
    }

    vector::vector(const vector &v) : v_(NULL),
                                      sz_(v.sz_)
    {
        crea_vector_();

        for (size_t i{0}; i < sz_; i++)
            v_[i] = v.v_[i];
    }

    vector &vector::operator=(const vector &v)
    {
        if (this != &v)
        {
            destruye_vector_();

            sz_ = v.sz_;
            crea_vector_();

            for (size_t i{0}; i < sz_; i++)
                v_[i] = v.v_[i];
        }

        return *this;
    }

    vector::~vector(void)
    {
        destruye_vector_();
    }

    size_t vector::size(void) const
    {
        return sz_;
    }

    double vector::at(const size_t pos) const
    {
        assert(pos < sz_);

        return v_[pos];
    }

    double &vector::at(const size_t pos)
    {
        assert(pos < sz_);

        return v_[pos];
    }

    double vector::operator[](const size_t pos) const
    {
        return at(pos);
    }

    double &vector::operator[](const size_t pos)
    {
        return at(pos);
    }

    std::ostream &vector::write(std::ostream &os) const
    {
        os << std::setw(MAX_WIDE) << std::fixed << std::setprecision(0) << sz_ << std::endl;

        for (size_t i{0}; i < sz_; i++)
            os << std::setw(MAX_WIDE) << std::fixed << std::setprecision(MAX_PRECISION) << v_[i] << " ";

        return os;
    }

    std::istream &vector::read(std::istream &is)
    {
        is >> sz_;

        destruye_vector_();
        crea_vector_();

        for (size_t i{0}; i < sz_; i++)
            is >> v_[i];

        return is;
    }

    void vector::crea_vector_(void)
    {
        v_ = new double[sz_];
    }

    void vector::destruye_vector_(void)
    {
        if (v_ != NULL)
        {
            delete[] v_;
            v_ = NULL;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const AyED::vector &v)
{
    v.write(os);
    return os;
}

std::istream &operator>>(std::istream &is, AyED::vector &v)
{
    return v.read(is);
}


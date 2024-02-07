#include "vector_t.hpp"

#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cassert>

namespace AyED
{

    vector_t::vector_t(void) : base_(NULL),
                               sz_(0)
    {
    }

    vector_t::vector_t(size_t sz) : base_(NULL),
                                    sz_(sz)
    {
        build(sz_);
    }

    vector_t::vector_t(const vector_t &v) : base_(NULL),
                                            sz_(v.sz_)
    {
        build(sz_);

        for (int i = 0; i < sz_; i++)
            base_[i] = v.base_[i];
    }

    vector_t::~vector_t(void)
    {
        destroy();
    }

    void vector_t::resize(size_t sz)
    {
        destroy();
        sz_ = sz;
        build(sz_);
    }

    size_t vector_t::size(void) const
    {
        return sz_;
    }

    double &vector_t::at(size_t i)
    {
        assert(i < sz_);

        return base_[i];
    }

    double vector_t::at(size_t i) const
    {
        assert(i < sz_);

        return base_[i];
    }

    std::ostream &vector_t::write(std::ostream &os) const
    {
        os << std::setw(8) << sz_ << std::endl;

        for (int i = 0; i < sz_; i++)
            os << std::setw(8) << std::fixed << std::setprecision(4) << base_[i] << " ";

        os << std::endl;
    }

    std::istream &vector_t::read(std::istream &is)
    {
        is >> sz_;

        resize(sz_);

        for (int i = 0; i < sz_; i++)
            is >> base_[i];
    }

    double &vector_t::operator[](size_t i)
    {
        return at(i);
    }

    double vector_t::operator[](size_t i) const
    {
        return at(i);
    }

    void vector_t::build(size_t sz)
    {
        base_ = new double[sz];
    }

    void vector_t::destroy(void)
    {
        if (base_ != NULL)
        {
            delete[] base_;
            base_ = NULL;
        }
    }

    size_t vector_t::ocurrencias(double d, double eps) const
    {
        size_t cnt = 0;

        for (size_t i = 0; i < sz_; i++)
            if (fabs(base_[i] - d) < eps)
                cnt++;

        return cnt;
    }

    double vector_t::scalprod(const vector_t &v) const
    {
        double prod = 0.0;

        for (size_t i = 0; i < sz_; i++)
            prod += base_[i] * v.base_[i];

        return prod;
    }

}

double operator*(const AyED::vector_t &v, const AyED::vector_t &w)
{
    return v.scalprod(w);
}

std::ostream &operator<<(std::ostream &os, const AyED::vector_t &v)
{
    return v.write(os);
}

std::istream &operator>>(std::istream &is, AyED::vector_t &v)
{
    return v.read(is);
}

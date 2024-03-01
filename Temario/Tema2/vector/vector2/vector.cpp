#include "vector.hpp"

#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cassert>

namespace AyED
{

    vector::vector(void) : base_(NULL),
                               sz_(0)
    {
    }

    vector::vector(size_t sz) : base_(NULL),
                                    sz_(sz)
    {
        build(sz_);
    }

    vector::vector(const vector &v) : base_(NULL),
                                            sz_(v.sz_)
    {
        build(sz_);

        for (int i{0}; i < sz_; i++)
            base_[i] = v.base_[i];
    }

    vector::~vector(void)
    {
        destroy();
    }

    void vector::resize(size_t sz)
    {
        destroy();
        sz_ = sz;
        build(sz_);
    }

    size_t vector::size(void) const
    {
        return sz_;
    }

    double &vector::at(size_t i)
    {
        assert(i < sz_);

        return base_[i];
    }

    double vector::at(size_t i) const
    {
        assert(i < sz_);

        return base_[i];
    }

    std::ostream &vector::write(std::ostream &os) const
    {
        os << std::setw(8) << sz_ << std::endl;

        for (int i{0}; i < sz_; i++)
            os << std::setw(8) << std::fixed << std::setprecision(4) << base_[i] << " ";

        os << std::endl;
    }

    std::istream &vector::read(std::istream &is)
    {
        is >> sz_;

        resize(sz_);

        for (int i{0}; i < sz_; i++)
            is >> base_[i];
    }

    double &vector::operator[](size_t i)
    {
        return at(i);
    }

    double vector::operator[](size_t i) const
    {
        return at(i);
    }

    void vector::build(size_t sz)
    {
        base_ = new double[sz];
    }

    void vector::destroy(void)
    {
        if (base_ != NULL)
        {
            delete[] base_;
            base_ = NULL;
        }
    }

    size_t vector::ocurrencias(double d, double eps) const
    {
        size_t cnt{0};

        for (size_t i{0}; i < sz_; i++)
            if (fabs(base_[i] - d) < eps)
                cnt++;

        return cnt;
    }

    double vector::scalprod(const vector &v) const
    {
        double prod = 0.0;

        for (size_t i{0}; i < sz_; i++)
            prod += base_[i] * v.base_[i];

        return prod;
    }

}

double operator*(const AyED::vector &v, const AyED::vector &w)
{
    return v.scalprod(w);
}

std::ostream &operator<<(std::ostream &os, const AyED::vector &v)
{
    return v.write(os);
}

std::istream &operator>>(std::istream &is, AyED::vector &v)
{
    return v.read(is);
}

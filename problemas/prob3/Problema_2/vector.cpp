#include "vector.hpp"

#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <cassert>

namespace AyED
{

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

    void vector::init_random(const double min, const double max)
    {
        for (size_t i{0}; i < sz_; i++)
            v_[i] = min + (max - min) * (rand() / (RAND_MAX + 1.0));
    }

    void vector::sort(void)
    {
        for (size_t i{0}; i < sz_; i++)
        {
            const size_t smaller_inx{smaller_inx_(i, sz_ - 1)};
            swap_(i, smaller_inx);
        }
    }

    bool vector::sequential_search(const double val, const double eps, size_t &pos) const
    {
        bool found{false};

        for (size_t i{0}; (i < sz_) && (!found); i++)
        {
            if (std::abs(v_[i] - val) < eps)
            {
                pos = i;
                found = true;
            }
        }

        return found;
    }

    bool vector::binary_search(const double val, const double eps, size_t &pos) const
    {
        bool found{false};

        size_t left{0};
        size_t right{sz_ - 1};

        if (v_[left] > val)
            return false;

        if (v_[right] < val)
            return false;

        while ((left <= right) && (!found))
        {
            const size_t middle{(left + right) / 2};

            if (std::abs(v_[middle] - val) < eps)
            {
                pos = middle;
                found = true;
            }
            else if (v_[middle] < val)
                left = middle + 1;
            else
                right = middle - 1;
        }

        return found;
    }

    void vector::swap_(const size_t a, const size_t b)
    {
        assert(a < sz_);
        assert(b < sz_);

        const double tmp{v_[a]};
        v_[a] = v_[b];
        v_[b] = tmp;
    }

    size_t vector::smaller_inx_(const size_t a, const size_t b) const
    {
        assert(a < sz_);
        assert(b < sz_);
        assert(a <= b);

        size_t smaller_inx{a};
        double smaller{v_[a]};

        for (size_t i{a + 1}; i <= b; i++)
            if (v_[i] < smaller)
            {
                smaller = v_[i];
                smaller_inx = i;
            }

        return smaller_inx;
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

#include "i_vector.hpp"

#include <cassert>
#include <iomanip>

namespace AyED
{

    i_vector::i_vector(int a, int b) : vector(b - a + 1), a_(a), b_(b) {}

    i_vector::~i_vector(void) {}

    double i_vector::at(const int pos) const
    {
        assert (pos >= a_);
        assert (pos <= b_);

        return vector::at(pos - a_);
    }

    double &i_vector::at(const int pos)
    {
        assert (pos >= a_);
        assert (pos <= b_);

        return vector::at(pos - a_);
    }

    double i_vector::operator[](const int pos) const
    {
        return at(pos);
    }

    double &i_vector::operator[](const int pos)
    {
        return at(pos);
    }

    std::ostream& i_vector::write(std::ostream &os) const
    {
        return vector::write(os);
    }
}

std::ostream &operator<<(std::ostream &os, const AyED::i_vector &v)
{
    return v.write(os);
}
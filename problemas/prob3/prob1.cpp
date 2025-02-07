#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

#include <cassert>

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

    vector::vector(void) : v_(NULL),
                           sz_(0) {}

    vector::vector(size_t sz) : v_(NULL),
                                sz_(sz)
    {
        crea_vector_();
    }

    vector::~vector(void)
    {
        destruye_vector_();
    }

    size_t vector::size(void) const
    {
        return sz_;
    }

    const double &vector::at(size_t pos) const
    {
        assert(pos < sz_);

        return v_[pos];
    }

    double &vector::at(size_t pos)
    {
        assert(pos < sz_);

        return v_[pos];
    }

    const double &vector::operator[](size_t pos) const
    {
        return at(pos);
    }

    double &vector::operator[](size_t pos)
    {
        return at(pos);
    }

    double vector::scalar_product(const vector &v) const
    {
        assert(sz_ == v.size());

        double result{0};

        for (size_t i{0}; i < sz_; i++)
            result += v_[i] * v[i];

        return result;
    }

    bool vector::perpendicular(const double precision, const vector &v) const
    {
        assert(sz_ == v.size());

        const double result{scalar_product(v)};

        if (fabs(result) < precision)
            return true;
        else
            return false;
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

double operator*(const AyED::vector &v1, const AyED::vector &v2)
{
    return v1.scalar_product(v2);
}

int main(void)
{
    const double precision{1e-3};

    AyED::vector v1;

    std::cout << "Leyendo vector v1" << std::endl;
    std::cin >> v1;
    std::cout << v1 << std::endl;
    std::cout << std::endl;

    AyED::vector v2;

    std::cout << "Leyendo vector v2" << std::endl;
    std::cin >> v2;
    std::cout << v2 << std::endl;
    std::cout << std::endl;

    std::cout << "Producto escalar: ";
    std::cout << std::setw(MAX_WIDE) << std::fixed << std::setprecision(MAX_PRECISION) << v1 * v2 << std::endl;
    std::cout << std::endl;

    std::cout << "Los vectores v1 y v2";
    if (v1.perpendicular(precision, v2))
        std::cout << " son perpendiculares" << std::endl;
    else
        std::cout << " no son perpendiculares" << std::endl;
    std::cout << std::endl;

    AyED::vector v3;

    std::cout << "Leyendo vector v3" << std::endl;
    std::cin >> v3;
    std::cout << v3 << std::endl;
    std::cout << std::endl;

    AyED::vector v4;

    std::cout << "Leyendo vector v4" << std::endl;
    std::cin >> v4;
    std::cout << v4 << std::endl;
    std::cout << std::endl;

    std::cout << "Producto escalar: ";
    std::cout << std::setw(MAX_WIDE) << std::fixed << std::setprecision(MAX_PRECISION) << v3 * v4 << std::endl;
    std::cout << std::endl;

    std::cout << "Los vectores v3 y v4";
    if (v3.perpendicular(precision, v4))
        std::cout << " son perpendiculares" << std::endl;
    else
        std::cout << " no son perpendiculares" << std::endl;
    std::cout << std::endl;

    return 0;
}

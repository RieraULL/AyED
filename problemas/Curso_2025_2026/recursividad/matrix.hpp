#include "vector.hpp"

namespace AyED
{

    class matrix : private AyED::vector
    {

    public:
        matrix(size_t m, size_t n);
        ~matrix(void);

        void resize(size_t m, size_t n);

        size_t get_m(void) const;
        size_t get_n(void) const;

        int &at(const size_t i, const size_t j);
        int at(const size_t i, const size_t j) const;

        int operator()(const size_t i, const size_t j) const;
        int &operator()(const size_t i, const size_t j);

        std::ostream &write(std::ostream &os) const;

    private:
        size_t pos_(const size_t i, const size_t j) const;

    private:
        size_t m_;
        size_t n_;
    };

    std::ostream &operator<<(std::ostream &os, const matrix &A);
}
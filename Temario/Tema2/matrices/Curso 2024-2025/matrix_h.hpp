#include "vector.hpp"

namespace AyED
{

    class matrix_h : private vector
    {

    public:
        matrix_h(size_t m, size_t n);
        ~matrix_h(void);

        void resize(size_t m, size_t n);

        size_t get_m(void) const;
        size_t get_n(void) const;

        double &at(const size_t i, const size_t j);
        double at(const size_t i, const size_t j) const;

        double operator()(const size_t i, const size_t j) const;
        double &operator()(const size_t i, const size_t j);

        std::ostream &write(std::ostream &os) const;

        void init_random(int seed);

        double suma_total(void) const;
        double suma_diag_p(void) const;
        double suma_diag_s(void) const;
        double suma_tria_inf_diag(void) const;
        double suma_tria_inf(void) const;
        double suma_tria_sup_diag(void) const;
        double suma_tria_sup(void) const;

        void traspuesta_cuadrada(void);

        void swap_rows(const size_t i, const size_t j);
        void swap_cols(const size_t i, const size_t j);

        void mult_row(const size_t i, const double k);
        void mult_col(const size_t j, const double k);

        void sum_row(const size_t i, const size_t j, const double k);
        void sum_col(const size_t i, const size_t j, const double k);

        void suma(const matrix_h &A, const matrix_h &B);
        void producto(const matrix_h &A, const matrix_h &B);

        void Gauss_Jordan(void);

    private:
        size_t pos_(const size_t i, const size_t j) const;

    private:
        size_t m_;
        size_t n_;
    };

    std::ostream &operator<<(std::ostream &os, const matrix_h &A);
}
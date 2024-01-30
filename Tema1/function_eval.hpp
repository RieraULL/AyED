#pragma once

#include <iostream>

typedef double (*funtion_ptr)(double);

namespace AyED
{
    class function_evaluation
    {
    private:
        double left_limit_;
        double right_limit_;
        double tol_;

        int n_;

        double *x_;
        double *y_;

    public:
        function_evaluation(const double left, const double right, const double tol = 1E-2);
        ~function_evaluation(void);

        void evaluate(const funtion_ptr f);

        void set_limits(const double left, const double right, const double tol = 1E-2);

        std::ostream &write(std::ostream &os) const;

    private:
        void create_vectors(void);
        void free_vectors(void);
    };

}
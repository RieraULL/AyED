#pragma once

#include <iostream>
#include <vector>

typedef double (*funtion_ptr)(double);

namespace AyED
{
    class function_evaluation
    {
    public:
        function_evaluation(const double left, const double right, const double tol, const funtion_ptr f);
        ~function_evaluation(void);

        std::ostream &write(std::ostream &os) const;

        double get_left_limit(void) const;
        double get_right_limit(void) const;
        double get_tolerance(void) const;

    private:
        void build_x(const double left, const double right, const double tol, double *x_points);
        void evaluate_function(const double *x_points, double *y_points, const funtion_ptr f);

        int compute_n_points(const double left, const double right, const double tol);
        void build_dynamic_memory_vector(double **v);
        void release_dynamic_memory_vector(double **v);

    private:
        double *x_points_;
        double *y_points_;
        int    n_points_;
    };
}

std::ostream &operator<<(std::ostream &os, const AyED::function_evaluation &f);
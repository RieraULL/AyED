#include "function_eval.hpp"

#include <cmath>
#include <cassert>

#include <iostream>
#include <iomanip>

namespace AyED
{

    function_evaluation::function_evaluation(const double left, const double right, const double tol, const funtion_ptr f) 
    {
        assert(right + tol > left);

        n_points_ = compute_n_points(left, right, tol);  // Calcula el número de puntos a evaluar

        build_dynamic_memory_vector(&x_points_);         // Reserva memoria dinámica para el vector x_points_
        build_dynamic_memory_vector(&y_points_);         // Reserva memoria dinámica para el vector y_points_

        build_x(left, right, tol, x_points_);            // Construye el vector x_points_

        evaluate_function(x_points_, y_points_, f);      // Evalúa la función en los puntos x_points_
    }

    function_evaluation::~function_evaluation(void)
    {
        release_dynamic_memory_vector(&x_points_);       // Libera la memoria dinámica del vector x_points_
        release_dynamic_memory_vector(&y_points_);       // Libera la memoria dinámica del vector y_points_
    }

    int function_evaluation::compute_n_points(const double left, const double right, const double tol)
    {
        return ceil((right - left) / tol) + 1;
    }

    void function_evaluation::build_dynamic_memory_vector(double **v)
    {
        *v = new double[n_points_];
    }

    void function_evaluation::release_dynamic_memory_vector(double **v)
    {
        assert(*v != nullptr);

        delete[] *v;
        *v = nullptr;
    }

    
    void function_evaluation::build_x(const double left, const double right, const double tol, double *x_points)
    {
        double point = left;

        int i = 0;

        while (point <= right)
        {
            x_points[i] = point;

            point += tol;
            i++;
        }

        if ((x_points[i - 1] != right) && (i < n_points_ - 1))
        {
            x_points[i] = right;
            i++;
        }

        assert(i <= n_points_);

        n_points_ = i;
    }

    void function_evaluation::evaluate_function(const double *x_points, double *y_points, const funtion_ptr f)
    {
        for (int i = 0; i < n_points_; i++)
        {
            y_points[i] = f(x_points[i]);
        }
    }

    std::ostream &function_evaluation::write(std::ostream &os) const
    {
        os << "#" << std::setw(10) << "x" << std::setw(10) << "f(x)" << std::endl;
        for (int i = 0; i < n_points_; ++i)
        {
            os << " " << std::setw(10) << std::fixed << std::setprecision(3) << x_points_[i] << std::setw(10)  << std::fixed << std::setprecision(3) << y_points_[i] << std::endl;
        }

        return os;
    }

    double function_evaluation::get_left_limit(void) const
    {
        return x_points_[0];
    }

    double function_evaluation::get_right_limit(void) const
    {
        return x_points_[n_points_ - 1];
    }

    double function_evaluation::get_tolerance(void) const
    {
        assert(n_points_ > 1);

        return x_points_[1] - x_points_[0];
    }

}

std::ostream &operator<<(std::ostream &os, const AyED::function_evaluation &f)
{
    return f.write(os);
}

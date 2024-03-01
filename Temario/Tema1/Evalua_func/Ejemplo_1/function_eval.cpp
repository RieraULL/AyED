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

        build_x(left, right, tol, x_points_);
        evaluate_function(x_points_, y_points_, f);
    }

    function_evaluation::~function_evaluation(void)
    {
    }

    
    void function_evaluation::build_x(const double left, const double right, const double tol, points_container &x_points)
    {
        double point = left;

        while (point <= right)
        {
            x_points.push_back(point);
            point += tol;
        }

        if (x_points.back() != right)
        {
            x_points.push_back(right);
        }
    }

    void function_evaluation::evaluate_function(const points_container &x_points, points_container &y_points, const funtion_ptr f)
    {
        for (auto x : x_points)
        {
            y_points.push_back(f(x));
        }
    }

    std::ostream &function_evaluation::write(std::ostream &os) const
    {
        os << "#" << std::setw(10) << "x" << std::setw(10) << "f(x)" << std::endl;
        for (size_t i{0}; i < x_points_.size(); ++i)
        {
            os << " " << std::setw(10) << std::fixed << std::setprecision(3) << x_points_[i] << std::setw(10)  << std::fixed << std::setprecision(3) << y_points_[i] << std::endl;
        }

        return os;
    }

    double function_evaluation::get_left_limit(void) const
    {
        return x_points_.front();
    }

    double function_evaluation::get_right_limit(void) const
    {
        return x_points_.back();
    }

    double function_evaluation::get_tolerance(void) const
    {
        assert(x_points_.size() > 1);

        return x_points_[1] - x_points_[0];
    }

}

std::ostream &operator<<(std::ostream &os, const AyED::function_evaluation &f)
{
    return f.write(os);
}

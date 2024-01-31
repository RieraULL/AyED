#pragma once

#include <iostream>
#include <vector>

typedef double (*funtion_ptr)(double);
typedef std::vector<double> points_container;

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
        void build_x(const double left, const double right, const double tol, points_container &x_points);
        void evaluate_function(const points_container &x_points, points_container &y_points, const funtion_ptr f);

    private:
        points_container x_points_;
        points_container y_points_;
    };
}

std::ostream &operator<<(std::ostream &os, const AyED::function_evaluation &f);
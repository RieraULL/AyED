#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

namespace AyED
{

	class point_t
	{
	public:
		point_t(void) : x_(0),
						y_(0) {}

		point_t(double x, double y) : x_(x),
									  y_(y) {}

		~point_t(void) {}

		double get_x(void) const { return x_; }
		double get_y(void) const { return y_; }

		void set(double x, double y)
		{

			x_ = x;
			y_ = y;
		}

		void write(std::ostream &os) const
		{

			os << "(";
			os << std::setw(6) << std::fixed << std::setprecision(2) << x_;
			os << ",";
			os << std::setw(6) << std::fixed << std::setprecision(2) << y_;
			os << ")";
		}

		double distance_L2(const point_t &p)
		{
			return sqrt((p.x_ - x_) * (p.x_ - x_) + (p.y_ - y_) * (p.y_ - y_));
		}

		double distance_L1(const point_t &p)
		{
			return fabs(p.x_ - x_) + fabs(p.y_ - y_);
		}

	private:
		double x_;
		double y_;
	};
}
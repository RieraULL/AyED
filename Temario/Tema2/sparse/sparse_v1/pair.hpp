#pragma once

#include <iostream>
#include <iomanip>

namespace AyED
{

	class pair
	{
	private:
		int inx_;
		double val_;

	public:
		pair(void) : inx_(-1),
					 val_(0.0) {}

		pair(int inx, double val) : inx_(inx),
									val_(val) {}

		~pair(void) {}

		void set(int inx, double val)
		{

			inx_ = inx;
			val_ = val;
		}

		int get_inx(void) const { return inx_; }
		double get_val(void) const { return val_; }

		std::ostream &write(std::ostream &os) const
		{

			os << "( "<< std::setw(5) << inx_ << ", " << std::setw(5) << std::fixed << std::setprecision(2) << val_ << " ) ";
			return os;
		}

		std::istream &read(std::istream &is)
		{

			is >> inx_ >> val_;
			return is;
		}
	};

}
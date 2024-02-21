#pragma once

#include <iostream>
#include <iomanip>

namespace AyED
{

	template <class T>
	class pair
	{
	private:
		int inx_;
		T val_;

	public:
		pair(void) : inx_(-1),
					   val_() {}

		pair(int inx, T val) : inx_(inx),
								 val_(val) {}

		~pair(void) {}

		void set(int inx, T val)
		{

			inx_ = inx;
			val_ = val;
		}

		int get_inx(void) const { return inx_; }
		T get_val(void) const { return val_; }

		std::ostream &write(std::ostream &os) const
		{

			os << std::setw(6) << inx_ << " " << std::setw(5) << val_;
			return os;
		}

		std::istream &read(std::istream &is)
		{

			is >> inx_ >> val_;
			return is;
		}
	};
}

template <>
std::ostream &AyED::pair<double>::write(std::ostream &os) const
{

	os << " ( " << std::setw(6) << inx_ << ", " << std::setw(5) << std::fixed << std::setprecision(1) << val_ << " )";
	return os;
}

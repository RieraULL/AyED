#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>


namespace AyED
{

	class vector
	{
	private:
		double *v_;
		int sz_;

	public:
		vector(void) : v_(NULL),
					   sz_(0) {}

		vector(int sz) : v_(NULL),
						 sz_(sz)
		{

			crea_vector();
		}

		~vector(void)
		{

			destruye_vector();
		}

		void resize(int sz)
		{
			destruye_vector();
			sz_ = sz;
			crea_vector();
		}

		int size(void) const
		{
			return sz_;
		}

		double at(int pos) const
		{

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		double &at(int pos)
		{

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		std::ostream &write(std::ostream &os) const
		{

			os << std::setw(8) << sz_ << std::endl;

			for (int i = 0; i < sz_; i++)
				os << std::setw(8) << std::fixed << std::setprecision(2) << v_[i] << " ";

			return os;
		}

		std::istream &read(std::istream &is)
		{

			is >> sz_;

			resize(sz_);

			for (int i = 0; i < sz_; i++)
				is >> v_[i];

			return is;
		}

	private:
		void crea_vector(void)
		{
			v_ = new double[sz_];
		}

		void destruye_vector(void)
		{
			if (v_ != NULL)
			{
				delete[] v_;
				v_ = NULL;
			}
		}
	};
}
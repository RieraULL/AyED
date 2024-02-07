#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

namespace AyED
{

	template <class T>
	class vector
	{
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

		const T &at(int pos) const
		{

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		T &at(int pos)
		{

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		const T &operator[](int pos) const
		{
			return at(pos);
		}

		T &operator[](int pos)
		{
			return at(pos);
		}

		std::ostream &write(std::ostream &os) const
		{

			os << sz_ << std::endl;

			for (int i = 0; i < sz_; i++)
				os << v_[i] << " ";

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
			v_ = new T[sz_];
		}

		void destruye_vector(void)
		{
			if (v_ != NULL)
			{
				delete[] v_;
				v_ = NULL;
			}
		}

	private:
		T *v_;
		int sz_;
	};

	template <>
	std::ostream &vector<double>::write(std::ostream &os) const
	{

		os << std::setw(8) << sz_ << std::endl;

		for (int i = 0; i < sz_; i++)
			os << std::setw(8) << std::fixed << std::setprecision(2) << v_[i] << " ";

		return os;
	}

}
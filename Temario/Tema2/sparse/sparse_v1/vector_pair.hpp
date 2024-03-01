#pragma once

#include "pair.hpp"
#include <cstdio>

#include <iostream>
#include <iomanip>

#include <cassert>

namespace AyED
{

	class vector_pair
	{
	private:
		pair *v_;
		int sz_;

	public:
		vector_pair(void) : v_(NULL),
							sz_(0) {}

		vector_pair(int sz) : v_(NULL),
							  sz_(sz)
		{

			crea_vector();
		}

		~vector_pair(void)
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

		pair at(int pos) const
		{

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		pair &at(int pos)
		{

			assert((pos < sz_) && ((pos >= 0)));

			return v_[pos];
		}

		std::ostream &write(std::ostream &os) const
		{

			for (int i{0}; i < sz_; i++)
			{
				v_[i].write(os);
				os << " ";
			}

			return os;
		}

		std::istream &read(std::istream &is)
		{

			is >> sz_;

			resize(sz_);

			for (int i{0}; i < sz_; i++)
				v_[i].read(is);

			return is;
		}

	private:
		void crea_vector(void)
		{
			v_ = new pair[sz_];
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
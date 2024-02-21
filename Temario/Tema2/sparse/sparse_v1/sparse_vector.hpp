#pragma once

#include "pair.hpp"
#include "vector_pair.hpp"
#include "vector.hpp"

#include <cmath>

#include <iostream>
#include <iomanip>

namespace AyED
{

	class sparse_vector
	{
	private:
		vector_pair v_; // Vector de pares
		int sz_;		// Tamaño del vector original

	public:
		sparse_vector(void) : v_(),
							  sz_(0) {}

		sparse_vector(const vector &v, double eps) : v_(),
													   sz_(v.get_sz())
		{

			// Cuenta el número de elementos no nulos
			int nz = 0;

			for (int i = 0; i < v.get_sz(); i++)
				if (is_not_zero(v.get_v(i), eps))
					nz++;

			v_.resize(nz);

			nz = 0;

			for (int i = 0; i < v.get_sz(); i++)
				if (is_not_zero(v.get_v(i), eps))
				{
					v_.get_set_v(nz).set(i, v.get_v(i));
					nz++;
				}
		}

		~sparse_vector(void) {}

		std::ostream &write(std::ostream &os) const
		{

			os << std::setw(7) << sz_ << " ";
			os << "[ ";
			v_.write(os);
			os << " ]";

			return os;
		}

	private:
		bool is_not_zero(double val, double eps) { return fabs(val) > eps; }
	};

}
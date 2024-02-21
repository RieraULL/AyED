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

		sparse_vector(const vector<double> &v, double eps) : v_(),
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
			v_.write(os);

			return os;
		}

		double scal_prod(const vector<double> &v) const
		{
			double res = 0.0;

			for (int i = 0; i < v_.get_sz(); i++)
				res += v_.get_v(i).get_val() * v.get_v(v_.get_v(i).get_inx());

			return res;
		}

		double scal_prod(const sparse_vector &v) const
		{
			double res = 0.0;

			int i = 0, j = 0;

			while ((i < v_.get_sz()) && (j < v.v_.get_sz()))
			{
				if (v_.get_v(i).get_inx() == v.v_.get_v(j).get_inx())
				{
					res += v_.get_v(i).get_val() * v.v_.get_v(j).get_val();
					i++;
					j++;
				}
				else if (v_.get_v(i).get_inx() < v.v_.get_v(j).get_inx())
					i++;
				else
					j++;
			}

			return res;
		}

	private:
		bool is_not_zero(double val, double eps) { return fabs(val) > eps; }
	};
}
  
double operator*(const AyED::vector<double> &v, const AyED::sparse_vector &sv)
{
	return sv.scal_prod(v);
}

double operator*(const AyED::sparse_vector &sv, const AyED::vector<double> &v)
{
	return sv.scal_prod(v);
}

double operator*(const AyED::sparse_vector &sv1, const AyED::sparse_vector &sv2)
{
	return sv1.scal_prod(sv2);
}

std::ostream &operator<<(std::ostream &os, const AyED::sparse_vector &sv)
{
	return sv.write(os);
}

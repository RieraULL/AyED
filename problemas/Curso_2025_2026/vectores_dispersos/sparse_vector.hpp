#pragma once

#include "pair.hpp"
#include "vector_pair.hpp"
#include "vector.hpp"

#include <cmath>
#include <unordered_map>

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
															 sz_(v.size())
		{

			// Cuenta el número de elementos no nulos
			int nz{0};

			for (int i{0}; i < v.size(); i++)
				if (is_not_zero(v.at(i), eps))
					nz++;

			v_.resize(nz);

			nz = 0;

			for (int i{0}; i < v.size(); i++)
				if (is_not_zero(v.at(i), eps))
				{
					v_.at(nz).set(i, v.at(i));
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

			for (int i{0}; i < v_.size(); i++)
				res += v_.at(i).get_val() * v.at(v_.at(i).get_inx());

			return res;
		}

		// Producto escalar asumiendo índices ordenados (búsqueda lineal)
		double scal_prod(const sparse_vector &v) const
		{
			double res = 0.0;

			int i{0}, j{0};

			while ((i < v_.size()) && (j < v.v_.size()))
			{
				if (v_.at(i).get_inx() == v.v_.at(j).get_inx())
				{
					res += v_.at(i).get_val() * v.v_.at(j).get_val();
					i++;
					j++;
				}
				else if (v_.at(i).get_inx() < v.v_.at(j).get_inx())
					i++;
				else
					j++;
			}

			return res;
		}

		// Producto escalar sin asumir índices ordenados (búsqueda lineal)
		double scal_prod_linear(const sparse_vector &v) const
		{
			double res = 0.0;

			for (int i{0}; i < v_.size(); i++)
			{
				int idx_this = v_.at(i).get_inx();
				double val_this = v_.at(i).get_val();

				// Buscar el índice correspondiente en el otro vector
				for (int j{0}; j < v.v_.size(); j++)
				{
					if (v.v_.at(j).get_inx() == idx_this)
					{
						res += val_this * v.v_.at(j).get_val();
						break;
					}
				}
			}

			return res;
		}

		// Distancia euclidiana entre dos vectores dispersos
		double euclidean_distance(const sparse_vector &v) const
		{
			// dist = sqrt(||v1||^2 + ||v2||^2 - 2*(v1·v2))
			double norm_invocante = scal_prod(*this);  // v1 · v1
			double norm_v = v.scal_prod(v);       // v2 · v2
			double product_escalar = scal_prod(v);    // v1 · v2

			double dist_squared = std::max(0.0, norm_invocante + norm_v - 2.0 * product_escalar);

			return std::sqrt(dist_squared);
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

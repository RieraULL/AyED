#include "vector.hpp"
#include "sparse_vector.hpp"

#include <iostream>
#include <cstdlib>

#define V_SZ 10000
#define EPS  1E-3

int main(void)
{
	AyED::vector<double> v(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v.get_set_v(i) = 0.0;

	v[0]    = 1.0; 
	v[1000] = 1.0; 
	v[2000] = 1.0; 
	v[3000] = 1.0; 
	v[4000] = 1.0; 
	v[5000] = 1.0;

	AyED::sparse_vector sv(v, EPS);	

	std::cout << sv << std::endl;

	// -------------------------------------

	AyED::vector<double> v1(V_SZ);

	// Rellena v1 con valores aleatorios

	for(int i = 0; i < V_SZ; i++)
		v1.get_set_v(i) = (rand() % 1000) / 100.0;


	const double producto_1 = sv.scal_prod(v1);
	const double producto_2 = v1 * sv;
	const double producot_3 = sv * v1;


	
}

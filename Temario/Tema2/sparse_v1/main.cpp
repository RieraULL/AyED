#include "vector.hpp"
#include "sparse_vector.hpp"

#include <iostream>

#define V_SZ 10000
#define EPS  1E-3

int main(void)
{
	AyED::vector v(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v.get_set_v(i) = 0.0;

	v.get_set_v(0)    = 1.0; 
	v.get_set_v(1000) = 1.0; 
	v.get_set_v(2000) = 1.0; 
	v.get_set_v(3000) = 1.0; 
	v.get_set_v(4000) = 1.0; 
	v.get_set_v(5000) = 1.0;

	AyED::sparse_vector sv(v, EPS);	

	sv.write(std::cout);
	std::cout << std::endl;
}

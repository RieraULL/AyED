#include "vector.hpp"
#include "sparse_vector.hpp"

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

#define V_SZ 10000
#define NZ 8
#define EPS  1E-3

int main(void)
{
	srand (time(NULL));

	AyED::vector<double> v1(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v1[i] = 0.0;

	for(int i = 0; i < NZ; i++)
		v1[rand() % V_SZ] = (rand() % 1000) / 100.0;

	AyED::sparse_vector sv1(v1, EPS);	

	std::cout << "Muestra vector disperso sv1" << std::endl;
	std::cout << std::endl;
	std::cout << sv1 << std::endl;

	AyED::vector<double> v2(V_SZ);

	for(int i = 0; i < V_SZ; i++)
		v2[i] = 0.0;

	for(int i = 0; i < NZ; i++)
		v2[rand() % V_SZ] = (rand() % 1000) / 100.0;	

	AyED::sparse_vector sv2(v2, EPS);

	std::cout << "Muestra vector disperso sv2" << std::endl;
	std::cout << std::endl;
	std::cout << sv2 << std::endl;

	const double producto_1 = v1 * sv1;
	const double producto_2 = sv1 * v1;

	const double producto_3 = sv2 * v2;
	const double producto_4 = v2 * sv2;

	const double producto_5 = sv1 * sv2;
	const double producto_6 = sv1 * sv1;
	const double producto_7 = sv2 * sv2;

	std::cout << "Muestra productos escalares" << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(8) << std::fixed << std::setprecision(1) << producto_1 << std::endl;
	std::cout << std::setw(8) << std::fixed << producto_2 << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(8) << std::fixed << producto_3 << std::endl;
	std::cout << std::setw(8) << std::fixed << producto_4 << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(8) << std::fixed << producto_5 << std::endl;
	std::cout << std::setw(8) << std::fixed << producto_6 << std::endl;
	std::cout << std::setw(8) << std::fixed << producto_7 << std::endl;
}

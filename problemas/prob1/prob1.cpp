#include <iostream>
#include <iomanip>
#include <cstdlib>

#define MAX_SZ 10
#define MAX_VAL 50

int scal_prod(int v1[], int v2[], int sz)
{
	int aux{0};

	for (int i{0}; i < sz; i++)
		aux = aux + v1[i] * v2[i];

	return aux;
}

int main(void)
{
	int v1[MAX_SZ], v2[MAX_SZ];

	for (int i{0}; i < MAX_SZ; i++)
	{

		v1[i] = rand() % (2 * (MAX_VAL + 1)) - MAX_VAL;
		v2[i] = rand() % (2 * (MAX_VAL + 1)) - MAX_VAL;
	}

	for (int i{0}; i < MAX_SZ; i++)
		std::cout << std::setw(4) << v1[i];

	std::cout << std::endl;

	for (int i{0}; i < MAX_SZ; i++)
		std::cout << std::setw(4) << v2[i];

	std::cout << std::endl;

	const int sp = scal_prod(v1, v2, MAX_SZ);

	std::cout << std::endl;
	std::cout << "  v1 . v2 = " << sp << std::endl;
}

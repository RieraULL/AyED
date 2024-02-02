#include <iostream>
#include <iomanip>
#include <cstdlib>

#define MAX_SZ 10

int suma(int v[], int sz)
{
	int aux = 0;

	for (int i = 0; i < sz; i++)
		aux = aux + v[i];

	return aux;
}

int cont_pair(int v[], int sz)
{
	int cont = 0;

	for (int i = 0; i < sz; i++)
		if (v[i] % 2 == 0)
			cont++;

	return cont;
}

int cont_odd(int v[], int sz)
{
	int cont = 0;

	for (int i = 0; i < sz; i++)
		if (v[i] % 2 != 0)
			cont++;

	return cont;
}

int main(void)
{
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	std::cout << "Suma   : " << std::setw(4) << suma(v, MAX_SZ) << std::endl;
	std::cout << "Pares  : " << std::setw(4) << cont_pair(v, MAX_SZ) << std::endl;
	std::cout << "Impares: " << std::setw(4) << cont_odd(v, MAX_SZ) << std::endl;
}

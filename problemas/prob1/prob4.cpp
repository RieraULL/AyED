#include <iostream>
#include <iomanip>
#include <cstdlib>

#define MAX_SZ  10

using namespace std;

int suma(int v[], int sz)
{
	int aux = 0;

	for(int i = 0; i < sz; i ++)
		aux = aux + v[i];

	return aux;
}

int cont_pair(int v[], int sz)
{
	int cont = 0;

	for(int i = 0; i < sz; i ++)
		 if (v[i] % 2 == 0)
			cont ++;

	return cont;
}

int cont_odd(int v[], int sz)
{
	int cont = 0;

	for(int i = 0; i < sz; i ++)
		 if (v[i] % 2 != 0)
			cont ++;

	return cont;
}


int main(void)
{
	int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


	cout << "Suma   : " << setw(4) << suma(v, MAX_SZ)      << endl;
	cout << "Pares  : " << setw(4) << cont_pair(v, MAX_SZ) << endl;
	cout << "Impares: " << setw(4) << cont_odd(v, MAX_SZ)  << endl;	
}


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define MAX_SZ  9
#define MAX_VAL 2

using namespace std;

int count_eq(double v[], int sz, double val, double tol)
{
	int count = 0;

	for(int i = 0; i < sz; i ++)
		if (fabs(v[i] - val) < tol)
			count ++;

	return count;
}

int main(void)
{
	double v1[] = {0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1};

	const int c1 = count_eq(v1, MAX_SZ, 1.0, 1E-4);
	const int c2 = count_eq(v1, MAX_SZ, 1.0, 1E-3);
	const int c3 = count_eq(v1, MAX_SZ, 1.0, 1E-2);
	const int c4 = count_eq(v1, MAX_SZ, 1.0, 1E-1);
	
	cout << "Tolerancia 1E-4: " << setw(2) << c1 << endl;
	cout << "Tolerancia 1E-3: " << setw(2) << c2 << endl;
	cout << "Tolerancia 1E-2: " << setw(2) << c3 << endl;
	cout << "Tolerancia 1E-1: " << setw(2) << c4 << endl;
}


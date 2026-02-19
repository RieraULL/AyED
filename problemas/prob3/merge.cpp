#include <iostream>

using namespace std;

void fusionSimple(const int a[], int na, const int b[], int nb, int c[], int &nc) {
	nc = 0;

	for (int i = 0; i < na; ++i) {
		c[nc] = a[i];
		++nc;
	}

	for (int j = 0; j < nb; ++j) {
		c[nc] = b[j];
		++nc;
	}
}

void fusionOrdenada(const int a[], int na, const int b[], int nb, int c[], int &nc) {
	int i = 0;
	int j = 0;
	nc = 0;

	while (i < na && j < nb) {
		if (a[i] <= b[j]) {
			c[nc] = a[i];
			++nc;
			++i;
		} else {
			c[nc] = b[j];
			++nc;
			++j;
		}
	}

	while (i < na) {
		c[nc] = a[i];
		++nc;
		++i;
	}

	while (j < nb) {
		c[nc] = b[j];
		++nc;
		++j;
	}
}

void fusionOrdenadaSinRepeticiones(const int a[], int na, const int b[], int nb, int c[], int &nc) {
	int i = 0;
	int j = 0;
	nc = 0;

	while (i < na && j < nb) {
		int valor;

		if (a[i] < b[j]) {
			valor = a[i];
			++i;
		} else if (b[j] < a[i]) {
			valor = b[j];
			++j;
		} else {
			valor = a[i];
			++i;
			++j;
		}

		if (nc == 0 || c[nc - 1] != valor) {
			c[nc] = valor;
			++nc;
		}
	}

	while (i < na) {
		int valor = a[i];
		++i;
		if (nc == 0 || c[nc - 1] != valor) {
			c[nc] = valor;
			++nc;
		}
	}

	while (j < nb) {
		int valor = b[j];
		++j;
		if (nc == 0 || c[nc - 1] != valor) {
			c[nc] = valor;
			++nc;
		}
	}
}

void imprimirVector(const int v[], int n, const char titulo[]) {
	cout << titulo << " [";
	for (int i = 0; i < n; ++i) {
		cout << v[i];
		if (i < n - 1) {
			cout << ", ";
		}
	}
	cout << "]\n";
}

int main() {
	const int TAM = 10;

	int a[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int b[TAM] = {2, 3, 4, 7, 8, 11, 12, 15, 18, 20};

	int c[2 * TAM];
	int nc = 0;

	imprimirVector(a, TAM, "Vector A:");
	imprimirVector(b, TAM, "Vector B:");
	cout << '\n';

	fusionSimple(a, TAM, b, TAM, c, nc);
	imprimirVector(c, nc, "1) Fusion simple (A seguido de B):");

	fusionOrdenada(a, TAM, b, TAM, c, nc);
	imprimirVector(c, nc, "2) Fusion ordenada:");

	fusionOrdenadaSinRepeticiones(a, TAM, b, TAM, c, nc);
	imprimirVector(c, nc, "3) Fusion ordenada sin repeticiones:");

	return 0;
}

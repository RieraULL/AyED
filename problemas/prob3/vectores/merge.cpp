#include "vector.hpp"

#include <iostream>
#include <limits>

using namespace std;

void fusionSimple(const AyED::vector &a, size_t na, const AyED::vector &b, size_t nb,
                  AyED::vector &c, size_t &nc) {
	nc = 0;

	for (size_t i = 0; i < na; ++i) {
		c[nc] = a[i];
		++nc;
	}

	for (size_t j = 0; j < nb; ++j) {
		c[nc] = b[j];
		++nc;
	}
}

void fusionOrdenada(const AyED::vector &a, size_t na, const AyED::vector &b, size_t nb,
                    AyED::vector &c, size_t &nc) {
	size_t i = 0;
	size_t j = 0;
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

void fusionOrdenadaSinRepeticiones(const AyED::vector &a, size_t na, const AyED::vector &b,
                                   size_t nb, AyED::vector &c, size_t &nc) {
	size_t i = 0;
	size_t j = 0;
	nc = 0;

	while (i < na && j < nb) {
		double valor;

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
		double valor = a[i];
		++i;
		if (nc == 0 || c[nc - 1] != valor) {
			c[nc] = valor;
			++nc;
		}
	}

	while (j < nb) {
		double valor = b[j];
		++j;
		if (nc == 0 || c[nc - 1] != valor) {
			c[nc] = valor;
			++nc;
		}
	}
}

void fusionOrdenadaConCentinela(const AyED::vector &a, size_t na, const AyED::vector &b,
                                size_t nb, AyED::vector &c, size_t &nc) {
	size_t i = 0;
	size_t j = 0;
	nc = 0;

	for (size_t k = 0; k < na + nb; ++k) {
		if (a[i] <= b[j]) {
			c[nc] = a[i];
			++i;
		} else {
			c[nc] = b[j];
			++j;
		}
		++nc;
	}
}

void imprimirVector(const AyED::vector &v, size_t n, const char titulo[]) {
	cout << titulo << " [";
	for (size_t i = 0; i < n; ++i) {
		cout << v[i];
		if (i < n - 1) {
			cout << ", ";
		}
	}
	cout << "]\n";
}

int main() {
	const size_t TAM = 10;
	const double INFINITO = numeric_limits<double>::max();

	AyED::vector a(TAM);
	AyED::vector b(TAM);
	AyED::vector aConCentinela(TAM + 1);
	AyED::vector bConCentinela(TAM + 1);

	AyED::vector c(2 * TAM);
	size_t nc = 0;

	a[0] = 1;
	a[1] = 3;
	a[2] = 5;
	a[3] = 7;
	a[4] = 9;
	a[5] = 11;
	a[6] = 13;
	a[7] = 15;
	a[8] = 17;
	a[9] = 19;

	b[0] = 2;
	b[1] = 3;
	b[2] = 4;
	b[3] = 7;
	b[4] = 8;
	b[5] = 11;
	b[6] = 12;
	b[7] = 15;
	b[8] = 18;
	b[9] = 20;

	for (size_t i = 0; i < TAM; ++i) {
		aConCentinela[i] = a[i];
		bConCentinela[i] = b[i];
	}
	aConCentinela[TAM] = INFINITO;
	bConCentinela[TAM] = INFINITO;

	imprimirVector(a, TAM, "Vector A:");
	imprimirVector(b, TAM, "Vector B:");
	cout << '\n';

	fusionSimple(a, TAM, b, TAM, c, nc);
	imprimirVector(c, nc, "1) Fusion simple (A seguido de B):");

	fusionOrdenada(a, TAM, b, TAM, c, nc);
	imprimirVector(c, nc, "2) Fusion ordenada:");

	fusionOrdenadaSinRepeticiones(a, TAM, b, TAM, c, nc);
	imprimirVector(c, nc, "3) Fusion ordenada sin repeticiones:");

	fusionOrdenadaConCentinela(aConCentinela, TAM, bConCentinela, TAM, c, nc);
	imprimirVector(c, nc, "4) Fusion ordenada con centinela:");

	return 0;
}

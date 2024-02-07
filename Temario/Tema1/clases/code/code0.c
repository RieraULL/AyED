/* Compilación: gcc -g code0.c -lm -o code0 */

#include <stdio.h>
#include <math.h>

#define EPS 1E-3

struct struct_complex {

	double r_;
	double i_;
};

typedef struct struct_complex complex; 

void inicializa_complejo1(complex* c, double r, double i)
{
	c->r_ = r;
	c->i_ = i;
}

void inicializa_complejo2(complex* c)
{
	c->r_ = 0;
	c->i_ = 0;
}


void imprime_complejo(complex* c)
{
	printf(" %3.1lf + %3.1lfi", c->r_, c->i_);
}

void set_real(complex* c, double r)
{
	c->r_ = r;
}
	
void set_imag(complex* c, double i)
{
	c->i_ = i;
}

double get_real(complex* c)
{
	return c->r_;
}

double get_imag(complex* c)
{
	return c->i_;
}

double get_modulo(complex* c)
{
	return sqrt(c->r_ * c->r_ + c->i_ * c->i_);	
}

double get_fase(complex* c)
{
	return atan2(c->i_, c ->r_);	
}

complex suma(complex* c1,complex* c2)
{
	complex aux;

	aux.r_ = c1->r_ + c2->r_;
	aux.i_ = c1->i_ + c2->i_;

	return aux;
}

complex producto(complex* c1,complex* c2)
{
	complex aux;

	aux.r_ = c1->r_ * c2->r_ - c1->i_ * c2->i_;
	aux.i_ = c1->r_ * c2->i_ + c2->r_ * c1->i_ ;

	return aux;	
}

int iguales(complex* c1,complex* c2)
{
	return ((fabs(c1->r_ - c2->r_) < EPS) && (fabs(c1->i_ - c2->i_) < EPS));
}

int main(void)
{	
	complex a,b,c,d;
	
	inicializa_complejo1(&a, 1, 2);
	inicializa_complejo1(&b, 2, 3);
	inicializa_complejo1(&c, 3, 4);
	inicializa_complejo2(&d);

	imprime_complejo(&a);
	printf("\n");
	imprime_complejo(&b);
	printf("\n");
	imprime_complejo(&c);
	printf("\n");
	imprime_complejo(&d);
	printf("\n");
	printf("\n");
	
	printf("Parte real      : %lf \n", get_real(&a));
	printf("Parte imaginaria: %lf \n", get_imag(&a));
	printf("Módulo          : %lf \n", get_modulo(&a));
	printf("Fase            : %lf \n", get_fase(&a));

	printf("Cambiando número: ");	
	imprime_complejo(&a); 

	set_real(&a,5);

	imprime_complejo(&a);
	printf("\n");

	printf("Suma             : ");
	imprime_complejo(&a);
	printf(" + ");
	imprime_complejo(&b);
	printf(" = ");
	c = suma(&a, &b);
	imprime_complejo(&c);
	printf("\n");

	printf("Producto         : ");
	imprime_complejo(&a);
	printf(" * ");
	imprime_complejo(&b);
	printf(" = ");
	d=  producto(&a, &b);
	imprime_complejo(&d);
	printf("\n");
}

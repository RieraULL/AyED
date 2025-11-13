# Problemas de examen resueltos I

## Problema 1

### Enunciado

Construir una función que devuelva el [producto escalar](https://es.wikipedia.org/wiki/Producto_escalar) de dos vectores. La cabecera de la función debe ser:

```cpp
int scal_prod(int v1[], int v2[], int sz)
```

Elabora, además, un programa principal en el que se inicialicen dos vectores `v1` y `v2` con números aleatorios con valores comprendidos entre -50 y 50, y que calcule el producto escalar entre ambos.

### Solución

Ref. [Prob1](prob1/prob1.cpp)

```cpp
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
```

## Problema 2

### Enunciado

Diseñar e implementar una función que devuelva el número de ocurrencias de un elemento `val` dentro de un vector de tipo `double`, con una tolerancia `tol`.
La cabecera del procedimiento debe ser

```cpp
int count_eq(double v[], int sz, double val, double tol)
```

Impleméntese, asimismo, un programa principal que inicialice un vector y muestre varios casos con distintas tolerancias.

### Solución

Ref. [Prob2](prob1/prob2.cpp)

```cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define MAX_SZ 9
#define MAX_VAL 2

int count_eq(double v[], int sz, double val, double tol)
{
	int count{0};

	for (int i{0}; i < sz; i++)
		if (fabs(v[i] - val) < tol)
			count++;

	return count;
}

int main(void)
{
	double v1[] = {0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1};

	const int c1 = count_eq(v1, MAX_SZ, 1.0, 1E-4);
	const int c2 = count_eq(v1, MAX_SZ, 1.0, 1E-3);
	const int c3 = count_eq(v1, MAX_SZ, 1.0, 1E-2);
	const int c4 = count_eq(v1, MAX_SZ, 1.0, 1E-1);

	std::cout << "Tolerancia 1E-4: " << std::setw(2) << c1 << std::endl;
	std::cout << "Tolerancia 1E-3: " << std::setw(2) << c2 << std::endl;
	std::cout << "Tolerancia 1E-2: " << std::setw(2) << c3 << std::endl;
	std::cout << "Tolerancia 1E-1: " << std::setw(2) << c4 << std::endl;
}
```

## Problema 3

### Enunciado

1. Diseñese e impleméntese una función que cuente el número de elementos menores que el valor `val` dentro de un vector `double` con una tolerancia `tol`.
2. Diseñese e impleméntese una función que cuente el número de elementos mayores que el valor `val` dentro de un vector `double` con una tolerancia `tol`.

La cabecera de los procedimientos debería ser:

```cpp
int count_less(double v[], int sz, double val, double tol)
int count_great(double v[], int sz, double val, double tol)
```

### Solución

Ref. [Prob3](prob1/prob3.cpp)

```cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define MAX_SZ 9
#define MAX_VAL 2

int count_less(double v[], int sz, double val, double tol)
{
	int count{0};

	for (int i{0}; i < sz; i++)
		if (v[i] - val < -tol)
			count++;

	return count;
}

int count_great(double v[], int sz, double val, double tol)
{
	int count{0};

	for (int i{0}; i < sz; i++)
		if (v[i] - val > tol)
			count++;

	return count;
}

int main(void)
{
	double v1[] = {0.9, 0.99, 0.999, 0.9999, 1.0, 1.0001, 1.001, 1.01, 1.1};

	const int c1 = count_less(v1, MAX_SZ, 1.0, 1E-4);
	const int c2 = count_less(v1, MAX_SZ, 1.0, 1E-3);
	const int c3 = count_less(v1, MAX_SZ, 1.0, 1E-2);
	const int c4 = count_less(v1, MAX_SZ, 1.0, 1E-1);

	const int c5 = count_great(v1, MAX_SZ, 1.0, 1E-4);
	const int c6 = count_great(v1, MAX_SZ, 1.0, 1E-3);
	const int c7 = count_great(v1, MAX_SZ, 1.0, 1E-2);
	const int c8 = count_great(v1, MAX_SZ, 1.0, 1E-1);

	std::cout << "LESS  Tolerancia 1E-4: " << std::setw(2) << c1 << std::endl;
	std::cout << "LESS  Tolerancia 1E-3: " << std::setw(2) << c2 << std::endl;
	std::cout << "LESS  Tolerancia 1E-2: " << std::setw(2) << c3 << std::endl;
	std::cout << "LESS  Tolerancia 1E-1: " << std::setw(2) << c4 << std::endl;
	std::cout << std::endl;
	std::cout << "GREAT Tolerancia 1E-4: " << std::setw(2) << c5 << std::endl;
	std::cout << "GREAT Tolerancia 1E-3: " << std::setw(2) << c6 << std::endl;
	std::cout << "GREAT Tolerancia 1E-2: " << std::setw(2) << c7 << std::endl;
	std::cout << "GREAT Tolerancia 1E-1: " << std::setw(2) << c8 << std::endl;
}
```

## Problema 4

### Enunciado

1. Diseñar e implementar una función que sume todos los elementos de un vector `int`.
2. Diseñar e implementar una función que cuente el número de elementos pares que hay dentro de un vector `int`.
3. Diseñar e implementar una función que cuente el número de elementos impares que hay dentro de un vector `int`.

Las cabeceras deberían ser de la siguiente manera:

```cpp
int suma(int v[], int sz)
int cont_pair(int v[], int sz)
int cont_odd(int v[], int sz)
```

### Solución

Ref. [Prob4](prob1/prob4.cpp)

```cpp
#include <iostream>
#include <iomanip>
#include <cstdlib>

#define MAX_SZ 10

int suma(int v[], int sz)
{
	int aux{0};

	for (int i{0}; i < sz; i++)
		aux = aux + v[i];

	return aux;
}

int cont_pair(int v[], int sz)
{
	int cont{0};

	for (int i{0}; i < sz; i++)
		if (v[i] % 2 == 0)
			cont++;

	return cont;
}

int cont_odd(int v[], int sz)
{
	int cont{0};

	for (int i{0}; i < sz; i++)
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
```

## Problema 5

### Enunciado

Diseñar e implementar una función que, dado un vector y una posición `pos` del mismo, sitúe el mayor de los elementos comprendidos entre las posiciones `0` y `pos` en la posición `pos`.

### Solución

Ref. [Prob5](prob1/prob5.cpp)

Compílese usando

```
g++ -g  prob5.cpp -o prob5
```

o

```
g++ -g -DDEBUGGING  prob5.cpp -o prob5
```

¿Cuál es la diferencia?

```cpp
template<class T>
void swap(T& a, T& b)
{
	T aux = a;
	a = b;
	b = aux;
}
```

El procedimiento `swap` intercambia el contenido de las dos variables `a` y `b`.

```cpp
template<class T>
bool unordered(const T& a, const T& b)
{
	return a > b;
}
```

La función `unordered` determina si las dos variables `a` y `b` están desordenadas. En concreto, devuelve `true` si `a > b`.

```cpp
template<class T>
void biggest_2_end(vector_t<T>& v, int end_v)
{
	for(int i{0}; i <= end_v - 1; i++)
		if (unordered<T>(v[i], v[i + 1]))
			swap<T>(v[i], v[i + 1]);
}
```

Finalmente, la función `biggest_2_end` mueve el mayor de los elementos situado entre las posiciones `0` y `end_v` a la posición `end_v`.

## Problema 6

### Enunciado

Diseñar e implementar una función que ordene en orden no decreciente utilizando la función desarrollada en el problema 5.

### Solución

Ref. [Prob6](prob1/prob5.cpp)

```cpp
template<class T>
void bubble_sort(vector_t<T>& v)
{
	for(int i = v.size() - 1; i >= 1; i--)
		 biggest_2_end<T>(v, i);
}
```

## Problema 7

### Enunciado

Diseñar e implementar una clase que represente un contenedor implementado por un `vector` que permita insertar elementos enteros de forma ordenada.

### Solución

Ref. [Prob7](prob1/prob6.cpp)

## Problema 8

### Enunciado

Diseñar e implementar una clase que represente una cola basada en una lista simplemente enlazada. Con ese propósito debe incluirse un puntero `tail` a la lista enlazada sobre la que se implementa la cola, con la posibilidad de hacer inserciones en `tail`. Así, debe haber un procedimiento de extracción por el `head` y uno de inserción por el `tail`.

### Solución

Ref. [Prob8](prob1/prob8.cpp)

## Problema 9

### Enunciado

Diseñese una clase que represente un número como un vector de dígitos representados en una base dada.

Con ese propósito mostraremos una propuesta:

```cpp
class number_t
{
private:
    vector<int>  number_;
	const int    base_;
	const char*  map_ = "0123456789ABCDEF";
```

En esta propuesta se utiliza un vector para almacenar los dígitos, un atributo que indica la base y una cadena de caracteres que facilitará la representación de números hasta base 16.

Impleméntense dos métodos: uno para obtener la representación en base decimal del número almacenado y otro para construir el vector de dígitos a partir de un número decimal.

```cpp
    int decimal(void) const
    {
        int aux{0};

        for(int i = n_digits() - 1; i >= 0; i--)
            aux += number_[i] * pow(base_, i);

        return aux;
    }

    void decimal(int num)
    {
        int aux = num;

        if (aux / pow(base_, n_digits() - 1) > base_) {
            cerr << "OVERFLOW ERROR!" << endl;
            exit(1);
        }

        for(int i = n_digits() - 1; i >= 0; i--) {
            number_[i] = aux / pow(base_, i);
            aux = aux % (int)(pow(base_, i));
        }
    }
```

Impleméntese un método recursivo que genere todos los números posibles a partir de la base y el número de dígitos especificado por la clase.

```cpp
	void generate(int i)
	{
	    if (i < 0) {

	        write(cout);
	        cout << endl;
	    }
	    else {

	        for(int b{0}; b < base_; b ++){
	            number_[i] = b;
	            generate(i - 1);
	        }
	    }
	}
```

Impleméntese un método no recursivo que genere todos los números posibles a partir de la base y el número de dígitos especificado por la clase. El procedimiento debe estar basado en una pila.

En primer lugar, defínase una clase de pares. Cada uno de estos dos elementos representa el valor de un dígito y la posición en el vector (o el nivel en el árbol de ramificación) del mismo.

```cpp
class par_t {
private:
  int b_;
  int level_;
public:
    par_t(int b, int level):
    b_(b), level_(level) {}

    ~par_t(void) {}

    int get_b(void) const {return b_;}
    int get_level(void) const {return level_;}
};
```

El siguiente procedimiento sigue un esquema similar al recorrido en profundidad de un árbol. Con ese fin, inicializa la pila con todos los posibles valores que puede tomar el último dígito.

Seguidamente, mientras la pila no esté vacía, se extrae el primer elemento disponible. Ese elemento indica el valor de un dígito y su posición dentro del vector. Se establece dicho valor en la posición indicada. Si la posición es la primera, se imprime el contenido del vector; en caso contrario, se introducen en la pila todos los posibles valores que pueden tener los dígitos en la posición precedente.

```cpp
	void generate_all2(void)
	{
	    stack<par_t> Pila;

	    for(int b{0}; b < base_; b++)
	        Pila.push(par_t(b, n_digits() - 1));

	    while(!Pila.empty())
	    {
	        const par_t par = Pila.top();
	        Pila.pop();

	        const int b = par.get_b();
	        const int l = par.get_level();

	        number_[l] = b;

	        if (l <= 0) {
	            write(cout);
	            cout << endl;
	        } else {
	            for(int b{0}; b < base_; b++)
	                Pila.push(par_t(b, l - 1));
	        }
	    }
	}
```

Sobrecárguese el operador pre-incremento. Con esta finalidad se incrementará el valor del primer dígito y se invocará un método recursivo que corrige el exceso en caso de que se produzca.

```cpp
	number_t& operator++(void)
	{
        number_[0]++;
        corrige_exceso(0);

		return *this;
	}
```

```cpp
	void corrige_exceso(int i)
	{
	    if (i < n_digits())
	    {
	        if (number_[i] >= base_) {

	            if(i + 1 < n_digits()) {

	                number_[i] = 0;
	                number_[i + 1]++;

	                corrige_exceso(i + 1);
	            }
	            else{
	                cerr << "OVERFLOW ERROR!!!" << endl;
	                exit(1);
	            }
	        }
	    }
	}
```

### Solución

Ref. [Prob9](prob1/prob9.cpp)

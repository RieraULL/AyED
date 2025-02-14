## Enunciado del Problema: vector double

Diseñe e implemente una clase denominada `vector` dentro del espacio de nombres `AyED` que represente un vector de elementos de tipo `double` utilizando memoria dinámica. La clase debe cumplir con los siguientes requisitos:

1.  **Atributos**:
    *   Un puntero a la base del vector (`double* v_`).
    *   El tamaño del vector (`size_t sz_`).

2.  **Constructores**:
    *   Constructor por defecto (`vector()`): Inicializa un vector vacío (tamaño 0).
    *   Constructor con tamaño (`vector(size_t sz)`): Crea un vector con `sz` elementos de tipo `double`, inicializados con valores por defecto (generalmente 0).
    *   Constructor de copia (`vector(const vector& v)`): Crea una copia profunda del vector `v`.

3.  **Destructor**:
    *   Destructor (`~vector()`): Libera la memoria dinámica utilizada por el vector.

4.  **Métodos de acceso**:
    *   `size_t size() const`: Devuelve el tamaño del vector.
    *   `double at(size_t pos) const`: Devuelve el elemento en la posición `pos`. Lanza una excepción si `pos` está fuera de rango.
    *   `double& at(size_t pos)`: Devuelve una referencia al elemento en la posición `pos`. Lanza una excepción si `pos` está fuera de rango.
    *   Sobrecarga del operador `[]`:
        *   `double operator[](size_t pos) const`: Devuelve el elemento en la posición `pos`. No realiza comprobación de límites (se asume que `pos` es válido).
        *   `double& operator[](size_t pos)`: Devuelve una referencia al elemento en la posición `pos`. No realiza comprobación de límites (se asume que `pos` es válido).

5.  **Métodos de modificación**:
    *   Sobrecarga del operador de asignación (`vector& operator=(const vector& v)`): Asigna el vector `v` al vector actual, realizando una copia profunda.

6.  **Operaciones con vectores**:
    *   `double scalar_product(const vector& v) const`: Calcula y devuelve el producto escalar del vector actual con el vector `v`. Si los vectores no tienen el mismo tamaño, se debe lanzar una excepción.
    *   `bool perpendicular(const vector& v, const double precision = 1E-3) const`: Determina si el vector actual es perpendicular al vector `v`, utilizando una precisión dada. Dos vectores se consideran perpendiculares si su producto escalar es cercano a cero (dentro de la precisión especificada).

7.  **Entrada/salida**:
    *   Sobrecarga del operador de inserción en flujo (`std::ostream& operator<<(std::ostream& os, const vector& v)`): Escribe el vector `v` en el flujo de salida `os` con un formato adecuado (por ejemplo, los elementos separados por comas y entre corchetes).
    *   Sobrecarga del operador de extracción de flujo (`std::istream& operator>>(std::istream& is, vector& v)`): Lee el vector desde el flujo de entrada `is`. Se espera un formato compatible con la salida (por ejemplo, elementos separados por comas y entre corchetes).

## Espacio de nombres y declaración de funciones externas

```c++
namespace AyED {
  class vector {
    // ... (atributos y métodos)
  };
} // namespace AyED

// Sobrecarga del operador de inserción en flujo
std::ostream& operator<<(std::ostream& os, const AyED::vector& v);

// Sobrecarga del operador de extracción de flujo
std::istream& operator>>(std::istream& is, AyED::vector& v);

// Sobrecarga del operador de multiplicación (producto escalar)
double operator*(const AyED::vector& v1, const AyED::vector& v2);
```

## Enunciado del Problema: vector genérico

Diseñe e implemente una clase genérica denominada `t_vector` dentro del espacio de nombres `AyED` que represente un vector de elementos de tipo `T` (donde `T` puede ser cualquier tipo de dato) utilizando memoria dinámica. La clase debe cumplir con los siguientes requisitos:

1.  **Atributos**:
    *   Un puntero a la base del vector (`T* v_`).
    *   El tamaño del vector (`size_t sz_`).

2.  **Constructores**:
    *   Constructor por defecto (`t_vector()`): Inicializa un vector vacío (tamaño 0).
    *   Constructor con tamaño (`t_vector(size_t sz)`): Crea un vector con `sz` elementos de tipo `T`. Los elementos no necesitan ser inicializados con valores específicos.
    *   Constructor de copia (`t_vector(const t_vector& v)`): Crea una copia profunda del vector `v`.

3.  **Destructor**:
    *   Destructor (`~t_vector()`): Libera la memoria dinámica utilizada por el vector.

4.  **Métodos de acceso**:
    *   `size_t size() const`: Devuelve el tamaño del vector.
    *   `const T& at(size_t pos) const`: Devuelve una referencia constante al elemento en la posición `pos`. Se debe realizar una comprobación de límites y lanzar una excepción (o usar `assert`) si `pos` está fuera de rango.
    *   `T& at(size_t pos)`: Devuelve una referencia al elemento en la posición `pos`. Se debe realizar una comprobación de límites y lanzar una excepción (o usar `assert`) si `pos` está fuera de rango.
    *   Sobrecarga del operador `[]`:
        *   `const T& operator[](size_t pos) const`: Devuelve una referencia constante al elemento en la posición `pos`. No es necesario realizar comprobación de límites.
        *   `T& operator[](size_t pos)`: Devuelve una referencia al elemento en la posición `pos`. No es necesario realizar comprobación de límites.

5.  **Métodos de modificación**:
    *   Sobrecarga del operador de asignación (`t_vector& operator=(const t_vector& v)`): Asigna el vector `v` al vector actual, realizando una copia profunda.

6.  **Entrada/salida**:
    *   `std::ostream& write(std::ostream& os) const`: Escribe el tamaño del vector seguido de sus elementos en el flujo de salida `os`.  El formato exacto de la salida queda a criterio del implementador, pero debe ser consistente.
    *   `std::istream& read(std::istream& is)`: Lee el tamaño del vector y sus elementos desde el flujo de entrada `is`. Se espera un formato compatible con la salida generada por `write`.

## Espacio de nombres y declaración de funciones externas (para tipos específicos)

```c++
namespace AyED {
  template <class T>
  class t_vector {
    // ... (atributos y métodos)
  };
} // namespace AyED

// Sobrecarga del operador de inserción en flujo para int
std::ostream& operator<<(std::ostream& os, const AyED::t_vector<int>& v);

// Sobrecarga del operador de extracción de flujo para int
std::istream& operator>>(std::istream& is, AyED::t_vector<int>& v);

// Sobrecarga del operador de inserción en flujo para double
std::ostream& operator<<(std::ostream& os, const AyED::t_vector<double>& v);

// Sobrecarga del operador de extracción de flujo para double
std::istream& operator>>(std::istream& is, AyED::t_vector<double>& v);
```
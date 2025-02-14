## Enunciado del Problema: Búsqueda en Vectores

Extienda la clase `vector` (previamente implementada) dentro del espacio de nombres `AyED` con métodos para realizar búsquedas secuenciales y binarias de elementos. La clase `vector` ahora deberá cumplir con los siguientes requisitos adicionales:

1.  **Métodos de búsqueda**:

    *   `bool sequential_search(const double val, const double eps, size_t& pos) const`: Realiza una búsqueda secuencial en el vector para encontrar un elemento cuyo valor sea igual a `val` dentro de una tolerancia `eps`.
        *   **Parámetros**:
            *   `val`: Valor a buscar.
            *   `eps`: Tolerancia (epsilon) para la comparación de valores en punto flotante. Se considera que dos números son iguales si su diferencia absoluta es menor que `eps`.
            *   `pos`: Parámetro de salida. Si se encuentra el valor, `pos` contendrá el índice del elemento encontrado.
        *   **Valor de retorno**: `true` si se encuentra el valor, `false` en caso contrario.

    *   `bool binary_search(const double val, const double eps, size_t& pos) const`: Realiza una búsqueda binaria en el vector para encontrar un elemento cuyo valor sea igual a `val` dentro de una tolerancia `eps`. **Este método solo debe utilizarse si el vector está ordenado de forma ascendente.**
        *   **Parámetros**:
            *   `val`: Valor a buscar.
            *   `eps`: Tolerancia (epsilon) para la comparación de valores en punto flotante.
            *   `pos`: Parámetro de salida. Si se encuentra el valor, `pos` contendrá el índice del elemento encontrado.
        *   **Valor de retorno**: `true` si se encuentra el valor, `false` en caso contrario.

2.  **Consideraciones adicionales para la búsqueda binaria:**

    *   Se debe asumir que el vector está ordenado ascendentemente antes de llamar a `binary_search`.  Si se llama a `binary_search` sobre un vector no ordenado, el comportamiento es indefinido y puede dar resultados incorrectos.
    *   Se recomienda incluir una aserción o comprobación (ej: `assert` en modo debug, o una excepción en release) dentro del método `binary_search` que verifique si el vector está ordenado.  Esta comprobación podría ser costosa en tiempo de ejecución, por lo que solo debería habilitarse en entornos de desarrollo o depuración.

## Ejemplo de uso

```c++
AyED::vector v(10); // Crea un vector de tamaño 10
// ... (Se llenan los elementos del vector)

double valor_a_buscar = 5.2;
double epsilon = 0.001;
size_t posicion;

if (v.sequential_search(valor_a_buscar, epsilon, posicion)) {
  std::cout << "Valor encontrado en la posición: " << posicion << std::endl;
} else {
  std::cout << "Valor no encontrado." << std::endl;
}

// Para usar la búsqueda binaria, el vector debe estar ordenado
// ... (Se ordenan los elementos del vector v)

if (v.binary_search(valor_a_buscar, epsilon, posicion)) {
  std::cout << "Valor encontrado (búsqueda binaria) en la posición: " << posicion << std::endl;
} else {
  std::cout << "Valor no encontrado." << std::endl;
}
```

## ¿Qué es la búsqueda binaria?

La búsqueda binaria es un algoritmo eficiente para encontrar un valor específico dentro de una colección de datos **ordenados**. Su funcionamiento se basa en dividir repetidamente la colección a la mitad y comparar el valor buscado con el elemento central.

1.  **Comienzo:** Se define un rango inicial que abarca toda la colección.
2.  **División:** Se calcula el punto medio del rango.
3.  **Comparación:** Se compara el valor buscado con el elemento en el punto medio.
    *   Si el valor buscado es igual al elemento central, se ha encontrado y la búsqueda termina.
    *   Si el valor buscado es menor que el elemento central, se reduce el rango a la mitad inferior.
    *   Si el valor buscado es mayor que el elemento central, se reduce el rango a la mitad superior.
4.  **Repetición:** Se repiten los pasos 2 y 3 hasta que se encuentra el valor o el rango se reduce a cero (lo que significa que el valor no está en la colección).


## Enunciado del Problema: Ordenación en la clase `vector`

Extienda la clase `vector` (previamente implementada) dentro del espacio de nombres `AyED` con un método para ordenar los elementos del vector utilizando el algoritmo de selección. La clase `vector` ahora deberá cumplir con los siguientes requisitos adicionales:

1.  **Método de ordenación:**

    *   `void sort()`: Ordena los elementos del vector en orden ascendente utilizando el algoritmo de selección.

2.  **Métodos auxiliares (privados):**

    *   `size_t smaller_inx_(const size_t a, const size_t b) const`: Encuentra el índice del elemento más pequeño en el subvector que va desde el índice `a` hasta el índice `b` (inclusive).
        *   **Precondiciones:** Se debe cumplir que `a < sz_`, `b < sz_` y `a <= b`.
        *   **Valor de retorno:** El índice del elemento más pequeño en el rango [`a`, `b`].

    *   `void swap_(const size_t a, const size_t b)`: Intercambia los elementos en las posiciones `a` y `b` del vector.
        *   **Precondiciones:** Se debe cumplir que `a < sz_` y `b < sz_`.

3.  **Algoritmo de Selección:**

    El método `sort()` debe implementar el algoritmo de selección de la siguiente manera:

    1.  Iterar desde el primer elemento hasta el penúltimo elemento del vector.
    2.  En cada iteración `i`, encontrar el índice del elemento más pequeño en el subvector que comienza en el índice `i` y termina en el último índice del vector.  Para ello, se utilizará el método auxiliar `smaller_inx_`.
    3.  Intercambiar el elemento en la posición `i` con el elemento encontrado en el paso anterior (el más pequeño del subvector). Para ello, se utilizará el método auxiliar `swap_`.

## Ejemplo de uso

```c++
AyED::vector v(10); // Crea un vector de tamaño 10
// ... (Se llenan los elementos del vector con valores desordenados)

std::cout << "Vector sin ordenar: " << v << std::endl;

v.sort(); // Ordena el vector

std::cout << "Vector ordenado: " << v << std::endl;
```
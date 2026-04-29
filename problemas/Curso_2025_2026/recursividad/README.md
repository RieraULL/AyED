# Recursion: recorridos sobre estructuras de datos

## Descripcion general

Este programa muestra recorridos recursivos e iterativos sobre tres estructuras de datos:

1. `AyED::vector`
2. `AyED::sll<int>` (lista simplemente enlazada)
3. `AyED::matrix`

La version actual simplifica varias firmas de funciones: se eliminan parametros redundantes (`n`, `m` o la propia lista en los recorridos recursivos de nodos) y se apoya en los metodos de cada estructura (`size()`, `get_m()`, `get_n()`).

## Funciones implementadas

### Vector

- `write_vector_recursive(const AyED::vector& vec, int i)`
   - Recorre e imprime de izquierda a derecha.
   - Caso base: `i == vec.size()`.

- `write_vector_iterative(const AyED::vector& vec)`
   - Version iterativa equivalente al recorrido directo.

- `write_vector_reverse_recursive(const AyED::vector& vec, int i)`
   - Recorre recursivamente y escribe en orden inverso (postorden).

- `write_vector_reverse_iterative(const AyED::vector& vec)`
   - Version iterativa inversa usando `AyED::stack_v<int>`.

### Lista simplemente enlazada

- `write_list_recursive(AyED::sll_node<int>* node)`
   - Recorre desde `head` hasta `NULL`.
   - Caso base: `node == NULL`.

- `write_list_reverse_recursive(AyED::sll_node<int>* node)`
   - Recorre recursivamente y escribe en orden inverso.

- `write_list_reverse_iterative(const AyED::sll<int>& L)`
   - Recorre la lista con un puntero y usa una pila para invertir la salida.

### Matriz

- `write_matrix_row_recursive(const AyED::matrix& M, int i, int j)`
   - Imprime la fila `i` desde la columna `j` hasta `M.get_n()`.

- `write_matrix_row_reverse_recursive(const AyED::matrix& M, int i, int j)`
   - Imprime la fila `i` en sentido inverso.

- `write_matrix_column_recursive(const AyED::matrix& M, int i, int j)`
   - Imprime la columna `j` desde la fila `i` hasta `M.get_m()`.

- `write_matrix_column_reverse_recursive(const AyED::matrix& M, int i, int j)`
   - Imprime la columna `j` en sentido inverso.

- `write_matrix_recursive(const AyED::matrix& M, int i, int j)`
   - Imprime toda la matriz fila a fila de forma recursiva.

- `write_matrix_reverse_recursive(const AyED::matrix& M, int i, int j)`
   - Imprime la matriz completa en orden inverso (ultimas filas y columnas primero).

## Flujo del main

1. Se crea un vector de 5 elementos con valores `1..5`.
2. Se muestra en orden normal e inverso, tanto recursivo como iterativo.
3. Se crea una lista simplemente enlazada con valores `1..5`.
4. Se muestra en orden normal (recursivo) e inverso (recursivo e iterativo).
5. Se crea una matriz de `3x4`.
6. La matriz se rellena con la formula `M(i, j) = i * M.get_n() + j + 1`.
7. Se imprime:
    - Matriz completa con `M.write(cout)`
    - Matriz recursiva
    - Matriz recursiva inversa
    - Fila 1 recursiva
    - Columna 2 recursiva

## Detalles importantes de esta version

- La matriz usa indexacion **1-based** (`i` y `j` empiezan en `1`).
- Los casos base en matriz se expresan como `i == M.get_m() + 1` o `j == M.get_n() + 1`.
- En los recorridos recursivos de lista ya no se pasa la lista completa, solo el nodo actual.
- Los recorridos inversos iterativos se apoyan en una pila explicita, equivalente a la pila implícita de la recursividad.

## Compilacion y ejecucion

```bash
g++ -std=c++11 -o recursividad recursividad.cpp vector.cpp matrix.cpp
./recursividad
```

## Ejercicios sugeridos

1. Implementar `sum_vector_recursive` para sumar elementos del vector.
2. Implementar `max_vector_recursive` para hallar el maximo.
3. Añadir version iterativa de recorrido de columna inversa en matriz.
4. Comparar coste temporal y espacial entre versiones recursivas e iterativas.

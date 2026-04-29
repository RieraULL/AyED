# Recursión: Recorridos sobre Estructuras de Datos

## Descripción General

Este programa ilustra los conceptos fundamentales de **recursión** mediante la implementación de diversos procedimientos que recorren diferentes estructuras de datos de forma tanto **recursiva como iterativa**. El objetivo es comprender cómo la recursión puede simplificar la lógica de ciertos algoritmos y cómo se relaciona con las estructuras iterativas equivalentes.

## Conceptos Clave de Recursión

### ¿Qué es la Recursión?

La recursión es una técnica de programación donde una función se invoca a sí misma para resolver un problema, dividiéndolo en subproblemas más pequeños del mismo tipo. Toda función recursiva debe tener:

1. **Caso Base**: Condición que detiene la recursión
2. **Caso Recursivo**: Invocación de la función con parámetros más cercanos al caso base

### Recursión vs Iteración

- **Iteración**: Usa bucles (`for`, `while`) para repetir acciones
- **Recursión**: Usa llamadas a función para lograr repetición
- Ambas pueden resolver los mismos problemas, pero la recursión es a menudo más elegante

## Estructuras de Datos Utilizadas

El programa trabaja con tres tipos de estructuras:

1. **Vector (`AyED::vector`)**: Array dinámico de enteros
2. **Lista Simplemente Enlazada (`AyED::sll<int>`)**: Lista con nodos conectados por punteros
3. **Matriz (`AyED::matrix`)**: Estructura bidimensional de enteros

## Funciones Implementadas

### 1. Operaciones con Vectores

#### `write_vector_recursive(const AyED::vector &vec, int n, int i)`
- **Propósito**: Escribe los elementos del vector en orden (primera a última)
- **Recursión**: Imprime el elemento `i`, luego avanza
- **Caso Base**: `i == n`
- **Complejidad**: O(n)

#### `write_vector_reverse_recursive(const AyED::vector &vec, int n, int i)`
- **Propósito**: Escribe los elementos del vector en orden inverso (última a primera)
- **Recursión**: Primero avanza recursivamente, luego imprime
- **Observación**: El orden de las operaciones (pre-orden vs post-orden) cambia el resultado
- **Complejidad**: O(n)

#### `write_vector_iterative(const AyED::vector &vec, int n)`
- **Propósito**: Equivalente iterativo de `write_vector_recursive`
- **Uso**: Comparar con la solución recursiva

#### `write_vector_reverse_iterative(const AyED::vector &vec, int n)`
- **Propósito**: Equivalente iterativo de `write_vector_reverse_recursive`
- **Técnica**: Usa una pila para simular la recursión
- **Concepto**: Demuestra la relación entre recursión y pilas

### 2. Operaciones con Listas Simplemente Enlazadas

#### `write_list_recursive(const AyED::sll<int> &L, AyED::sll_node<int> *node)`
- **Propósito**: Recorre y escribe una lista desde el inicio
- **Parámetro**: Puntero al nodo actual (comienza en `L.head()`)
- **Caso Base**: `node == NULL`

#### `write_list_reverse_recursive(const AyED::sll<int> &L, AyED::sll_node<int> *node)`
- **Propósito**: Recorre una lista de atrás hacia adelante sin usarla de forma doblemente enlazada
- **Técnica**: Post-orden recursivo
- **Ventaja**: No necesita conocer el tamaño de la lista de antemano

#### `write_list_reverse_iterative(const AyED::sll<int> &L)`
- **Propósito**: Equivalente iterativo usando una pila
- **Observación**: Idéntico al patrón de vector inverso iterativo

### 3. Operaciones con Matrices

#### `write_matrix_row_recursive(const AyED::matrix &M, int n, int m, int i, int j)`
- **Propósito**: Escribe una fila de la matriz recursivamente
- **Parámetros**: `n` = filas, `m` = columnas, `i` = fila, `j` = columna actual

#### `write_matrix_row_reverse_recursive(const AyED::matrix &M, int n, int m, int i, int j)`
- **Propósito**: Escribe una fila en orden inverso

#### `write_matrix_column_recursive(const AyED::matrix &M, int n, int m, int i, int j)`
- **Propósito**: Escribe una columna recursivamente

#### `write_matrix_column_reverse_recursive(const AyED::matrix &M, int n, int m, int i, int j)`
- **Propósito**: Escribe una columna en orden inverso

#### `write_matrix_recursive(const AyED::matrix &M, int n, int m, int i, int j)`
- **Propósito**: Escribe toda la matriz recursivamente
- **Técnica**: Combina recorridos de filas
- **Recursión doble**: Maneja dos dimensiones

#### `write_matrix_reverse_recursive(const AyED::matrix &M, int n, int m, int i, int j)`
- **Propósito**: Escribe toda la matriz en orden inverso

## Flujo del Programa Principal

```
1. Crear vector de 5 elementos [1, 2, 3, 4, 5]
   ├─ Mostrar vector recursivo
   ├─ Mostrar vector iterativo
   ├─ Mostrar vector inverso recursivo
   └─ Mostrar vector inverso iterativo

2. Crear lista simplemente enlazada con 5 elementos
   ├─ Mostrar lista recursiva
   ├─ Mostrar lista inversa recursiva
   └─ Mostrar lista inversa iterativa

3. Crear matriz 3×4
   ├─ Mostrar matriz completa
   ├─ Mostrar matriz recursiva
   ├─ Mostrar matriz inversa recursiva
   ├─ Mostrar fila 1 recursiva
   └─ Mostrar columna 2 recursiva
```

## Puntos de Aprendizaje Importantes

### 1. Orden de Operaciones
```cpp
// PRE-ORDEN: procesa, luego recurse
cout << elemento;
llamada_recursiva();

// POST-ORDEN: recurse, luego procesa
llamada_recursiva();
cout << elemento;
```

### 2. Relación Recursión-Pila
La recursión utiliza internamente la pila de llamadas del sistema. El programa demuestra cómo simular esto explícitamente con una estructura de pila.

### 3. Casos Base Correctos
Observar cómo cada función define su caso base (`i == n`, `node == NULL`, etc.)

### 4. Parámetros Acumuladores
Las funciones recursivas usan parámetros como `i` o `j` para mantener el estado de la recursión (acumulador).

## Compilación y Ejecución

### Requisitos
- Compilador C++ (C++11 o superior)
- Las siguientes cabeceras deben estar disponibles:
  - `vector.hpp`
  - `sll.hpp` (Single Linked List)
  - `sll_node.hpp`
  - `stack_v.hpp`
  - `matrix.hpp`

### Comando de Compilación
```bash
g++ -std=c++11 -o recursividad recursividad.cpp vector.cpp matrix.cpp
```

### Ejecución
```bash
./recursividad
```

## Ejercicios Propuestos

1. **Modificar** `write_vector_recursive` para calcular la suma de elementos
2. **Implementar** una función que encuentre el máximo elemento de un vector recursivamente
3. **Crear** una función recursiva que invierta una lista simplemente enlazada (modificando punteros)
4. **Extender** las operaciones de matriz para calcular determinantes recursivamente
5. **Comparar** tiempos de ejecución entre versiones recursivas e iterativas con estructuras grandes

## Notas Importantes

- Las funciones de matriz usan **indexación 1-based** (como se puede ver en `M(i, j)`)
- El parámetro `L` (lista) no se usa directamente en muchas funciones; se proporciona por claridad
- La complejidad temporal es O(n) o O(n²) según la estructura
- La complejidad espacial incluye el espacio de pila de recursión

## Referencia de Salida Esperada

El programa imprimirá:
- Vectores en orden normal y reverso (recursivo e iterativo)
- Listas enlazadas en orden normal y reverso
- Matriz completa
- Fila y columna específicas

Todos estos datos demuestran que tanto la recursión como la iteración producen los mismos resultados.

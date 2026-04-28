# Backtracking y Generacion Recursiva

Este directorio contiene un ejemplo en C++ con varios algoritmos recursivos de generacion exhaustiva.

Archivo principal:
- `backtracking.cpp`

## Proposito

Practicar el esquema de backtracking/recursion sobre espacios de soluciones discretas:
- Construir soluciones parciales posicion a posicion.
- Tomar decisiones en cada nivel del arbol de recursion.
- Alcanzar un caso base para emitir una solucion completa.

Aunque no todos los ejemplos hacen poda, todos siguen la idea central de explorar un arbol de decisiones.

## Algoritmos implementados

### 1) Generacion de cadenas binarias

Funcion: `generate_binary_recursive(x, n, i)`

- Genera todas las cadenas de longitud `n` con simbolos `{0, 1}`.
- En cada nivel `i`:
  - Asigna `0` y continua.
  - Asigna `1` y continua.
- Caso base: `i == n`, se imprime una solucion.

Complejidad:
- Tiempo: `O(2^n)` soluciones.
- Espacio auxiliar: `O(n)` por la profundidad de recursion.

### 2) Cadenas binarias que terminan en 0

Funciones:
- `generate_binary_pairs_recursive(x, n, i)` (version directa)
- `generate_binary_pairs_recursive_bad(x, n, i)` (version ineficiente)

Version directa:
- Fuerza el ultimo bit a `0` cuando llega a la penultima posicion.
- Solo genera soluciones validas.

Version ineficiente:
- Genera todas las cadenas binarias de longitud `n`.
- Filtra al final las que cumplen `x[n - 1] == 0`.

Comparacion:
- Ambas son correctas.
- La version directa es mejor porque reduce trabajo innecesario.

### 3) Generacion de numeros en base arbitraria

Funcion: `generate_numbers_recursive(x, n, i, base)`

- Generaliza la idea binaria a una base `base`.
- En cada posicion prueba todos los digitos `0..base-1`.
- Usa la cadena `digits = "0123456789ABCDEF"` para imprimir.

Restriccion importante:
- Tal como esta escrito, la impresion esta pensada para `base <= 16`.

Complejidad:
- Tiempo: `O(base^n)`.
- Espacio auxiliar: `O(n)`.

### 4) Generacion del conjunto potencia

Funciones:
- `generate_subsets_recursive(values, selected, i)`
- `write_subset(values, selected)`

Idea:
- `selected[i]` es una decision binaria:
  - `0`: no incluir `values[i]`.
  - `1`: incluir `values[i]`.
- Al llegar al final se imprime el subconjunto construido.

Resultado:
- Para un conjunto de `m` elementos se generan `2^m` subconjuntos.

## Estructura general del backtracking en este archivo

Patron comun en las funciones recursivas:
1. Comprobar caso base.
2. Si no se alcanza, expandir decisiones posibles.
3. Llamar recursivamente con la siguiente posicion.

Este patron corresponde al recorrido en profundidad (DFS) del arbol de soluciones.

## Compilacion y ejecucion

Desde esta carpeta:

```bash
g++ -std=c++17 -Wall -Wextra -pedantic backtracking.cpp -o backtracking
./backtracking
```

## Personalizacion rapida

En `main()` puedes modificar:
- `n` para cambiar la longitud de cadenas/numeros.
- `base` y `base2` para probar diferentes bases.
- `conjunto` para generar subconjuntos de otros valores.

# Tema 6: Recursividad y Backtracking

Este tema aborda dos técnicas algorítmicas fundamentales para resolver problemas complejos mediante descomposición y exploración sistemática del espacio de soluciones.

## Contenido

### Teoría

- **[Recursividad](Recursividad.md)** - Conceptos fundamentales, tipos de recursividad, ejemplos clásicos y análisis de complejidad.
- **[Backtracking](Backtracking.md)** - Técnica de vuelta atrás, esquema general, problemas clásicos y optimizaciones.

### Ejemplos prácticos

Todos los ejemplos están en la carpeta `ejemplos/` y pueden compilarse con el `Makefile` incluido.

#### Recursividad

1. **factorial_fibonacci.cpp** - Ejemplos básicos:
   - Factorial
   - Serie de Fibonacci
   - Potencia
   - Suma de dígitos
   - Máximo Común Divisor (MCD)

2. **torres_hanoi.cpp** - Torres de Hanoi:
   - Solución recursiva clásica
   - Visualización de movimientos
   - Cálculo de complejidad

#### Backtracking

3. **permutaciones.cpp** - Generador de permutaciones:
   - Genera todas las permutaciones de N elementos
   - Complejidad $O(n!)$

4. **n_reinas.cpp** - Problema de las N reinas:
   - Colocar N reinas en un tablero N×N sin ataques
   - Muestra todas las soluciones encontradas
   - Visualización del tablero

5. **subset_sum.cpp** - Suma de subconjuntos:
   - Encuentra subconjuntos cuya suma sea igual a un objetivo
   - Muestra todas las soluciones posibles
   - Incluye poda para optimizar la búsqueda

## Compilación

### Compilar todos los ejemplos

```bash
cd ejemplos
make all
```

### Compilar por categoría

```bash
make recursion      # Solo ejemplos de recursividad
make backtracking   # Solo ejemplos de backtracking
```

### Compilar ejemplo específico

```bash
make factorial_fibonacci
make torres_hanoi
make n_reinas
```

### Limpiar ejecutables

```bash
make clean
```

## Ejecución de ejemplos

### Factorial y Fibonacci

```bash
./factorial_fibonacci
```

Muestra tablas con valores de factorial, Fibonacci, potencias, suma de dígitos y MCD.

### Torres de Hanoi

```bash
./torres_hanoi
```

Solicita el número de discos y muestra todos los movimientos necesarios.

**Ejemplo**: Para 3 discos, genera 7 movimientos.

### Permutaciones

```bash
./permutaciones
```

Solicita cuántos elementos y genera todas las permutaciones.

**Ejemplo**: Para N=3, genera 6 permutaciones.

### N-Reinas

```bash
./n_reinas
```

Solicita el tamaño del tablero N y muestra todas las configuraciones válidas.

**Ejemplo**: Para N=4, encuentra 2 soluciones.

### Suma de subconjuntos

```bash
./subset_sum
```

Encuentra todos los subconjuntos de un conjunto dado cuya suma sea igual a un objetivo.

## Ejercicios propuestos

### Recursividad

1. **Búsqueda binaria recursiva**: Implementar búsqueda binaria de forma recursiva.
2. **Inversión de cadena**: Invertir una cadena usando recursividad.
3. **Palíndromo**: Verificar si una cadena es palíndromo recursivamente.
4. **Merge sort**: Implementar el algoritmo de ordenamiento merge sort.
5. **Quick sort**: Implementar el algoritmo de ordenamiento quick sort.

### Backtracking

1. **Sudoku solver**: Resolver un tablero de Sudoku usando backtracking.
2. **Problema del caballo**: Recorrer todo un tablero de ajedrez con movimientos de caballo.
3. **Laberinto**: Encontrar un camino en un laberinto desde entrada hasta salida.
4. **Coloración de grafos**: Asignar K colores a los nodos de un grafo sin que nodos adyacentes tengan el mismo color.
5. **Combinaciones**: Generar todas las combinaciones de K elementos de un conjunto de N elementos.

## Conceptos clave

- **Caso base**: Condición de parada en recursividad
- **Caso recursivo**: Llamada a la misma función con problema reducido
- **Stack overflow**: Error por exceso de profundidad en la pila de llamadas
- **Poda**: Eliminación de ramas del árbol de búsqueda en backtracking
- **Espacio de soluciones**: Conjunto de todas las posibles soluciones
- **Complejidad temporal**: Análisis mediante relaciones de recurrencia

## Complejidad típica

| Problema | Complejidad temporal | Complejidad espacial |
|----------|---------------------|---------------------|
| Factorial | $O(n)$ | $O(n)$ |
| Fibonacci (simple) | $O(2^n)$ | $O(n)$ |
| Torres de Hanoi | $O(2^n)$ | $O(n)$ |
| Permutaciones | $O(n!)$ | $O(n)$ |
| N-Reinas | $O(n!)$ | $O(n)$ |
| Subset Sum | $O(2^n)$ | $O(n)$ |

## Referencias

- [Recursión - Wikipedia](https://es.wikipedia.org/wiki/Recursi%C3%B3n)
- [Backtracking - Wikipedia](https://es.wikipedia.org/wiki/Vuelta_atr%C3%A1s)
- [Análisis de algoritmos recursivos](https://es.wikipedia.org/wiki/Relaci%C3%B3n_de_recurrencia)
- [Torres de Hanoi](https://es.wikipedia.org/wiki/Torres_de_Han%C3%B3i)
- [Problema de las N reinas](https://es.wikipedia.org/wiki/Problema_de_las_ocho_reinas)

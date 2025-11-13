# Backtracking

## Introducción

El **backtracking** (vuelta atrás) es una técnica algorítmica para resolver problemas de búsqueda y optimización mediante exploración sistemática del espacio de soluciones. Se basa en la construcción incremental de candidatos a solución y el abandono de aquellos que no cumplen las restricciones del problema (**poda**).

Es especialmente útil para problemas de:
- Búsqueda exhaustiva con restricciones
- Optimización combinatoria
- Problemas de satisfacción de restricciones (CSP)

## Principio fundamental

El backtracking explora el espacio de soluciones como un **árbol de decisiones**:

1. **Expandir**: Construir soluciones parciales añadiendo decisiones válidas.
2. **Validar**: Comprobar si la solución parcial puede conducir a una solución completa.
3. **Podar**: Si no es válida, retroceder (backtrack) y probar otra opción.
4. **Repetir**: Hasta encontrar todas las soluciones o la óptima.

## Esquema general

```cpp
bool backtrack(Estado& estado, Solucion& solucion) {
    // Caso base: solución completa
    if (es_solucion_completa(estado)) {
        procesar_solucion(solucion);
        return true;  // o false si buscamos todas las soluciones
    }
    
    // Generar candidatos
    for (auto candidato : generar_candidatos(estado)) {
        // Verificar si es válido (poda)
        if (es_valido(candidato, estado)) {
            // Aplicar decisión
            aplicar(candidato, estado, solucion);
            
            // Recursión
            if (backtrack(estado, solucion)) {
                return true;  // Solución encontrada
            }
            
            // Deshacer decisión (backtrack)
            deshacer(candidato, estado, solucion);
        }
    }
    
    return false;  // No hay solución en esta rama
}
```

## Ejemplo 1: Permutaciones

Generar todas las permutaciones de un conjunto de elementos.

### Implementación

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void imprimir_permutacion(const std::vector<int>& perm) {
    for (int x : perm) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void permutar(std::vector<int>& arr, int inicio) {
    // Caso base: hemos llegado al final
    if (inicio == arr.size()) {
        imprimir_permutacion(arr);
        return;
    }
    
    // Probar cada elemento en la posición actual
    for (int i = inicio; i < arr.size(); i++) {
        // Intercambiar
        std::swap(arr[inicio], arr[i]);
        
        // Recursión
        permutar(arr, inicio + 1);
        
        // Backtrack: deshacer intercambio
        std::swap(arr[inicio], arr[i]);
    }
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    std::cout << "Permutaciones de {1, 2, 3}:" << std::endl;
    permutar(arr, 0);
    return 0;
}
```

**Salida:**
```text
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
3 1 2
```

**Complejidad**: $O(n!)$ tiempo, $O(n)$ espacio (profundidad de recursión).

## Ejemplo 2: Subconjuntos (Power Set)

Generar todos los subconjuntos de un conjunto dado.

### Implementación

```cpp
#include <iostream>
#include <vector>

void imprimir_subconjunto(const std::vector<int>& subset) {
    std::cout << "{ ";
    for (int x : subset) {
        std::cout << x << " ";
    }
    std::cout << "}" << std::endl;
}

void generar_subconjuntos(const std::vector<int>& arr, 
                          std::vector<int>& subset,
                          int indice) {
    // Caso base: hemos considerado todos los elementos
    if (indice == arr.size()) {
        imprimir_subconjunto(subset);
        return;
    }
    
    // Opción 1: NO incluir el elemento actual
    generar_subconjuntos(arr, subset, indice + 1);
    
    // Opción 2: SÍ incluir el elemento actual
    subset.push_back(arr[indice]);
    generar_subconjuntos(arr, subset, indice + 1);
    subset.pop_back();  // Backtrack
}

int main() {
    std::vector<int> arr = {1, 2, 3};
    std::vector<int> subset;
    std::cout << "Subconjuntos de {1, 2, 3}:" << std::endl;
    generar_subconjuntos(arr, subset, 0);
    return 0;
}
```

**Complejidad**: $O(2^n)$ tiempo, $O(n)$ espacio.

## Ejemplo 3: Suma de subconjuntos (Subset Sum)

Encontrar un subconjunto de elementos cuya suma sea igual a un objetivo dado.

### Implementación

```cpp
#include <iostream>
#include <vector>

bool suma_objetivo(const std::vector<int>& arr,
                   std::vector<int>& solucion,
                   int indice,
                   int suma_actual,
                   int objetivo) {
    // Caso base: encontramos la suma objetivo
    if (suma_actual == objetivo) {
        std::cout << "Solución encontrada: { ";
        for (int x : solucion) {
            std::cout << x << " ";
        }
        std::cout << "}" << std::endl;
        return true;
    }
    
    // Poda: si nos pasamos o ya no hay elementos
    if (suma_actual > objetivo || indice == arr.size()) {
        return false;
    }
    
    // Opción 1: incluir elemento actual
    solucion.push_back(arr[indice]);
    if (suma_objetivo(arr, solucion, indice + 1, 
                      suma_actual + arr[indice], objetivo)) {
        return true;
    }
    solucion.pop_back();  // Backtrack
    
    // Opción 2: no incluir elemento actual
    return suma_objetivo(arr, solucion, indice + 1, 
                         suma_actual, objetivo);
}

int main() {
    std::vector<int> arr = {3, 34, 4, 12, 5, 2};
    std::vector<int> solucion;
    int objetivo = 9;
    
    std::cout << "Buscando subconjunto con suma = " << objetivo << std::endl;
    if (!suma_objetivo(arr, solucion, 0, 0, objetivo)) {
        std::cout << "No existe solución." << std::endl;
    }
    
    return 0;
}
```

## Ejemplo 4: N-Reinas

Colocar N reinas en un tablero de ajedrez N×N de forma que ninguna ataque a otra.

### Implementación

```cpp
#include <iostream>
#include <vector>
#include <cmath>

class NReinas {
private:
    int n;
    std::vector<int> tablero;  // tablero[i] = columna de la reina en fila i
    int soluciones_encontradas;
    
    bool es_seguro(int fila, int col) {
        // Verificar si hay conflicto con reinas anteriores
        for (int i = 0; i < fila; i++) {
            // Misma columna
            if (tablero[i] == col) return false;
            
            // Misma diagonal
            if (std::abs(tablero[i] - col) == std::abs(i - fila)) {
                return false;
            }
        }
        return true;
    }
    
    void imprimir_solucion() {
        std::cout << "Solución #" << soluciones_encontradas << ":" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << (tablero[i] == j ? "Q " : ". ");
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    void resolver(int fila) {
        // Caso base: todas las reinas colocadas
        if (fila == n) {
            soluciones_encontradas++;
            imprimir_solucion();
            return;
        }
        
        // Probar cada columna en esta fila
        for (int col = 0; col < n; col++) {
            if (es_seguro(fila, col)) {
                // Colocar reina
                tablero[fila] = col;
                
                // Recursión
                resolver(fila + 1);
                
                // Backtrack (implícito al probar siguiente columna)
            }
        }
    }
    
public:
    NReinas(int tamano) : n(tamano), tablero(tamano), soluciones_encontradas(0) {}
    
    void resolver() {
        resolver(0);
        if (soluciones_encontradas == 0) {
            std::cout << "No hay soluciones." << std::endl;
        } else {
            std::cout << "Total de soluciones: " << soluciones_encontradas << std::endl;
        }
    }
};

int main() {
    int n = 4;
    std::cout << "Resolviendo problema de " << n << " reinas:" << std::endl;
    NReinas problema(n);
    problema.resolver();
    return 0;
}
```

**Complejidad**: $O(n!)$ en el peor caso.

## Ejemplo 5: Laberinto

Encontrar un camino desde la entrada hasta la salida de un laberinto.

### Implementación

```cpp
#include <iostream>
#include <vector>

class Laberinto {
private:
    std::vector<std::vector<int>> maze;
    std::vector<std::vector<int>> solucion;
    int filas, columnas;
    
    // Direcciones: arriba, derecha, abajo, izquierda
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    bool es_valido(int x, int y) {
        return x >= 0 && x < filas && 
               y >= 0 && y < columnas && 
               maze[x][y] == 1 &&  // Celda transitable
               solucion[x][y] == 0;  // No visitada
    }
    
    bool resolver_aux(int x, int y, int destino_x, int destino_y) {
        // Caso base: llegamos al destino
        if (x == destino_x && y == destino_y) {
            solucion[x][y] = 1;
            return true;
        }
        
        // Marcar celda actual como parte del camino
        solucion[x][y] = 1;
        
        // Probar las 4 direcciones
        for (int i = 0; i < 4; i++) {
            int nuevo_x = x + dx[i];
            int nuevo_y = y + dy[i];
            
            if (es_valido(nuevo_x, nuevo_y)) {
                if (resolver_aux(nuevo_x, nuevo_y, destino_x, destino_y)) {
                    return true;
                }
            }
        }
        
        // Backtrack: desmarcar celda
        solucion[x][y] = 0;
        return false;
    }
    
public:
    Laberinto(const std::vector<std::vector<int>>& m) 
        : maze(m), filas(m.size()), columnas(m[0].size()) {
        solucion.resize(filas, std::vector<int>(columnas, 0));
    }
    
    bool resolver(int inicio_x, int inicio_y, int fin_x, int fin_y) {
        if (resolver_aux(inicio_x, inicio_y, fin_x, fin_y)) {
            std::cout << "Camino encontrado:" << std::endl;
            for (const auto& fila : solucion) {
                for (int celda : fila) {
                    std::cout << (celda ? "* " : ". ");
                }
                std::cout << std::endl;
            }
            return true;
        }
        std::cout << "No hay camino." << std::endl;
        return false;
    }
};

int main() {
    // 1 = transitable, 0 = muro
    std::vector<std::vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    
    Laberinto lab(maze);
    lab.resolver(0, 0, 3, 3);
    
    return 0;
}
```

## Técnicas de optimización

### 1. Poda (Pruning)

Eliminar ramas del árbol de búsqueda que no pueden conducir a una solución válida.

```cpp
// Ejemplo: en suma de subconjuntos
if (suma_actual > objetivo) {
    return;  // Poda: no seguir explorando
}
```

### 2. Ordenamiento de candidatos

Ordenar los candidatos para encontrar soluciones más rápido (heurística).

```cpp
// Probar primero los valores más prometedores
std::sort(candidatos.begin(), candidatos.end(), heuristica);
```

### 3. Memoización

Guardar resultados de subproblemas para evitar recalcularlos.

```cpp
std::unordered_map<Estado, bool> memo;

if (memo.count(estado)) {
    return memo[estado];
}
// ... calcular resultado ...
memo[estado] = resultado;
```

## Backtracking vs. Fuerza bruta

| Aspecto | Backtracking | Fuerza bruta |
|---------|--------------|--------------|
| **Exploración** | Poda ramas inválidas | Explora todo el espacio |
| **Eficiencia** | Mejor con buena poda | Ineficiente |
| **Memoria** | Usa la pila de recursión | Variable según implementación |
| **Aplicación** | Problemas con restricciones | Problemas pequeños |

## Problemas clásicos

1. **N-Reinas**: Colocar N reinas en un tablero N×N sin ataques.
2. **Sudoku**: Resolver un tablero de Sudoku.
3. **Coloración de grafos**: Asignar colores a nodos sin conflictos.
4. **Problema del caballo**: Recorrer un tablero con movimientos de caballo.
5. **Generación de combinaciones y permutaciones**.
6. **Problema de la mochila** (versión 0/1).
7. **Partición de conjuntos**.

## Análisis de complejidad

La complejidad temporal del backtracking depende de:
- Tamaño del espacio de búsqueda
- Efectividad de la poda

En general:
- **Peor caso**: Exploración exhaustiva del espacio $O(b^d)$ donde $b$ es el factor de ramificación y $d$ la profundidad.
- **Mejor caso con poda**: Puede reducirse drásticamente.

## Cuándo usar backtracking

- Problemas de búsqueda con restricciones
- Cuando no existe un algoritmo más eficiente conocido
- Espacios de soluciones que pueden podarse efectivamente
- Problemas de optimización combinatoria

## Ejercicios propuestos

1. Implementar Sudoku solver con backtracking.
2. Resolver el problema del caballo (knight's tour).
3. Generar todas las combinaciones de K elementos de N.
4. Resolver el problema de coloración de grafos.
5. Implementar el problema de la mochila 0/1.
6. Encontrar todas las formas de sumar monedas para un valor dado.

## Referencias

- [Backtracking - Wikipedia](https://es.wikipedia.org/wiki/Vuelta_atr%C3%A1s)
- [Problemas CSP](https://es.wikipedia.org/wiki/Problema_de_satisfacci%C3%B3n_de_restricciones)

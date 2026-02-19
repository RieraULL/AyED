# Recursividad

## Introducción

La **recursividad** es una técnica de programación en la que una función se invoca a sí misma, directa o indirectamente, para resolver un problema dividiéndolo en subproblemas más pequeños de la misma naturaleza. Es especialmente útil cuando el problema tiene una estructura inherentemente recursiva.

## Conceptos fundamentales

### Anatomía de una función recursiva

Toda función recursiva consta de dos elementos esenciales:

1. **Caso base** (o condición de parada): situación en la que la función devuelve un resultado sin realizar más llamadas recursivas. Evita la recursión infinita.
2. **Caso recursivo**: situación en la que la función se invoca a sí misma con un problema de menor tamaño.

### Esquema general

```cpp
tipo_retorno funcion_recursiva(parametros) {
    // Caso base
    if (condicion_de_parada) {
        return valor_base;
    }
    
    // Caso recursivo
    return combinacion_de(funcion_recursiva(parametros_reducidos));
}
```

## Ejemplo básico: Factorial

El factorial de un número $n$ se define como:

$$
n! = \begin{cases}
1 & \text{si } n = 0 \\
n \cdot (n-1)! & \text{si } n > 0
\end{cases}
$$

### Implementación recursiva

```cpp
#include <iostream>

unsigned long factorial(unsigned int n) {
    // Caso base
    if (n == 0 || n == 1) {
        return 1;
    }
    
    // Caso recursivo
    return n * factorial(n - 1);
}

int main() {
    std::cout << "5! = " << factorial(5) << std::endl;  // Salida: 120
    return 0;
}
```

**Traza de ejecución** para `factorial(5)`:

```
factorial(5) = 5 * factorial(4)
             = 5 * (4 * factorial(3))
             = 5 * (4 * (3 * factorial(2)))
             = 5 * (4 * (3 * (2 * factorial(1))))
             = 5 * (4 * (3 * (2 * 1)))
             = 120
```

## Ejemplo clásico: Serie de Fibonacci

La sucesión de Fibonacci se define como:

$$
F(n) = \begin{cases}
0 & \text{si } n = 0 \\
1 & \text{si } n = 1 \\
F(n-1) + F(n-2) & \text{si } n > 1
\end{cases}
$$

### Implementación recursiva

```cpp
#include <iostream>

unsigned long fibonacci(unsigned int n) {
    // Casos base
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Caso recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    for (int i = 0; i < 10; i++) {
        std::cout << "F(" << i << ") = " << fibonacci(i) << std::endl;
    }
    return 0;
}
```

**Nota**: Esta implementación tiene complejidad exponencial $O(2^n)$ debido a los cálculos redundantes. Puede optimizarse con memoización o programación dinámica.

## Recursividad en estructuras de datos

### Recorrido de listas enlazadas

```cpp
#include <iostream>

template<typename T>
struct Node {
    T data;
    Node* next;
    
    Node(T val) : data(val), next(nullptr) {}
};

template<typename T>
void print_list(Node<T>* node) {
    // Caso base: lista vacía
    if (node == nullptr) {
        return;
    }
    
    // Procesar nodo actual
    std::cout << node->data << " ";
    
    // Caso recursivo: procesar resto de la lista
    print_list(node->next);
}

template<typename T>
void print_list_reverse(Node<T>* node) {
    // Caso base
    if (node == nullptr) {
        return;
    }
    
    // Primero recorrer hasta el final
    print_list_reverse(node->next);
    
    // Luego imprimir (al regresar de la recursión)
    std::cout << node->data << " ";
}
```

### Recorrido de árboles binarios

```cpp
template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};

// Recorrido en preorden (raíz, izquierda, derecha)
template<typename T>
void preorder(TreeNode<T>* root) {
    if (root == nullptr) return;
    
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Recorrido en inorden (izquierda, raíz, derecha)
template<typename T>
void inorder(TreeNode<T>* root) {
    if (root == nullptr) return;
    
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

// Recorrido en postorden (izquierda, derecha, raíz)
template<typename T>
void postorder(TreeNode<T>* root) {
    if (root == nullptr) return;
    
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}
```

## Tipos de recursividad

### 1. Recursividad simple (o lineal)

Una única llamada recursiva en cada invocación.

```cpp
int suma_hasta(int n) {
    if (n == 0) return 0;
    return n + suma_hasta(n - 1);
}
```

### 2. Recursividad múltiple

Más de una llamada recursiva en cada invocación.

```cpp
// Fibonacci es un ejemplo de recursividad múltiple
unsigned long fibonacci(unsigned int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);  // Dos llamadas
}
```

### 3. Recursividad de cola (tail recursion)

La llamada recursiva es la última operación de la función. Puede optimizarse fácilmente a iteración.

```cpp
unsigned long factorial_tail(unsigned int n, unsigned long acumulador = 1) {
    if (n == 0 || n == 1) return acumulador;
    return factorial_tail(n - 1, n * acumulador);
}
```

### 4. Recursividad indirecta (mutua)

Dos o más funciones se invocan entre sí.

```cpp
bool es_par(int n);
bool es_impar(int n);

bool es_par(int n) {
    if (n == 0) return true;
    return es_impar(n - 1);
}

bool es_impar(int n) {
    if (n == 0) return false;
    return es_par(n - 1);
}
```

## Recursividad vs. Iteración

| Aspecto | Recursividad | Iteración |
|---------|--------------|-----------|
| **Legibilidad** | Más natural para problemas recursivos | Más directa para problemas simples |
| **Memoria** | Usa la pila de llamadas (stack) | Usa variables locales |
| **Eficiencia** | Puede ser menos eficiente por overhead | Generalmente más eficiente |
| **Riesgo** | Stack overflow si hay muchas llamadas | Bucles infinitos si mal diseñado |

### Cuándo usar recursividad

- Problemas con estructura naturalmente recursiva (árboles, grafos, divide y vencerás)
- Cuando simplifica significativamente el código
- Backtracking y búsqueda exhaustiva
- Algoritmos de tipo divide y vencerás (quicksort, mergesort)

### Cuándo evitar recursividad

- Problemas simples que se resuelven fácilmente con bucles
- Cuando la profundidad de recursión puede ser muy grande
- Recursiones con muchas llamadas redundantes sin memoización

## Análisis de complejidad

### Complejidad temporal

Se puede expresar mediante **relaciones de recurrencia**:

- **Factorial**: $T(n) = T(n-1) + O(1) \Rightarrow T(n) = O(n)$
- **Fibonacci (sin memoización)**: $T(n) = T(n-1) + T(n-2) + O(1) \Rightarrow T(n) = O(2^n)$
- **Búsqueda binaria**: $T(n) = T(n/2) + O(1) \Rightarrow T(n) = O(\log n)$

### Complejidad espacial

La profundidad de la pila de llamadas determina el espacio adicional:

- **Factorial**: $O(n)$ por la pila de llamadas
- **Fibonacci**: $O(n)$ en profundidad máxima
- **Recursión de cola optimizada**: $O(1)$ si el compilador la optimiza

## Errores comunes

### 1. Olvidar el caso base

```cpp
// ¡ERROR! Recursión infinita
int mal_factorial(int n) {
    return n * mal_factorial(n - 1);  // No hay caso base
}
```

### 2. Caso base incorrecto

```cpp
// ¡ERROR! No cubre todos los casos
int mal_fibonacci(int n) {
    if (n == 1) return 1;  // Falta el caso n == 0
    return mal_fibonacci(n - 1) + mal_fibonacci(n - 2);
}
```

### 3. No reducir el problema

```cpp
// ¡ERROR! El problema no se reduce
int bucle_infinito(int n) {
    if (n == 0) return 0;
    return bucle_infinito(n);  // ¡n no cambia!
}
```

## Ejercicios propuestos

1. Implementar una función recursiva que calcule $a^n$ (potencia).
2. Calcular el máximo común divisor (MCD) usando el algoritmo de Euclides recursivo.
3. Implementar la búsqueda binaria de forma recursiva.
4. Calcular la suma de los dígitos de un número entero.
5. Invertir una cadena de caracteres de forma recursiva.
6. Implementar las Torres de Hanoi.

## Referencias

- [Recursión - Wikipedia](https://es.wikipedia.org/wiki/Recursi%C3%B3n)
- [Análisis de algoritmos recursivos](https://es.wikipedia.org/wiki/Relaci%C3%B3n_de_recurrencia)

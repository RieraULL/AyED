# Introducción a las Listas Simplemente Enlazadas

Las estructuras de datos son fundamentales en el campo de la informática, permitiéndonos organizar, gestionar y almacenar datos de manera eficiente. Entre estas estructuras, las listas enlazadas ocupan un lugar especial por su flexibilidad y eficiencia en ciertas operaciones. En este texto, nos centraremos en un tipo específico: las listas simplemente enlazadas.

## Concepto

Una lista simplemente enlazada es una colección secuencial de elementos, donde cada elemento está conectado al siguiente mediante un enlace o puntero. A diferencia de los arrays o vectores, en las listas enlazadas, los elementos no están almacenados en localizaciones contiguas de memoria, lo que permite una inserción y eliminación de nodos con una complejidad temporal constante \(O(1)\), siempre que tengamos acceso directo al nodo en cuestión.

## Componentes Clave

- **Nodo**: La unidad básica de una lista enlazada, que contiene dos partes principales: los datos y un puntero (o enlace) al siguiente nodo en la lista.
- **Cabeza (Head)**: El primer nodo de la lista, a través del cual se accede a toda la estructura.
- **Cola (Tail)**: El último nodo de la lista, que señala a un valor nulo, indicando el final de la lista.

## Ventajas

- **Flexibilidad en la gestión de memoria**: Al no requerir un bloque contiguo de memoria, las listas enlazadas pueden crecer dinámicamente, adaptándose a las necesidades de la aplicación.
- **Eficiencia en operaciones de inserción y eliminación**: Especialmente cuando se realizan al principio de la lista o cuando se tiene un puntero al nodo anterior al que se desea manipular.

## Desventajas

- **Acceso secuencial**: A diferencia de los arrays, no es posible acceder directamente a un elemento específico en tiempo constante. Para acceder a un elemento, es necesario recorrer la lista desde la cabeza hasta llegar al elemento deseado.
- **Consumo de memoria adicional**: Cada nodo requiere memoria extra para almacenar el puntero al siguiente nodo.

## Aplicaciones

Las listas simplemente enlazadas son especialmente útiles en situaciones donde las operaciones de inserción y eliminación son frecuentes y críticas en términos de rendimiento, y donde el acceso aleatorio a los elementos no es una prioridad. Algunos ejemplos incluyen la implementación de colas, pilas, y otras estructuras de datos complejas.

Puedes encontrar código de ejemplo sobre dos tipos de implementaciones en este repositorio. En primer lugar, una lista simplemente enlazada implementada con memoria dinámica [Code1](Dynamic/main_sll.cpp) [Code2](Dynamic/sll.hpp) [Code3](Dynamic/sll_node.hpp). En segundo lugar una lista simplemente enlazada implementada sobre una región de memoria simulada con un vector [Code4](Vector/main_sll.cpp) [Code5](Vector/memory.hpp) [Code6](Vector/sll.hpp) [Code7](Vector/sll_node.hpp) [Code8](Vector/vector.hpp).


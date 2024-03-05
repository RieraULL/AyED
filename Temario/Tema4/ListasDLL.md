# Lista Doblemente Enlazada

La **lista doblemente enlazada** es una estructura de datos fundamental en la ciencia de la computación, utilizada para almacenar una secuencia de elementos de manera ordenada. A diferencia de las listas simplemente enlazadas, cada nodo en una lista doblemente enlazada contiene dos referencias (o "punteros"): una al nodo siguiente y otra al nodo anterior en la secuencia. Esta característica bidireccional permite recorrer la lista en ambas direcciones, lo que facilita ciertas operaciones como la inserción y la eliminación de nodos.

## Características Principales

- **Nodos con doble enlace:** Cada nodo tiene un enlace al nodo siguiente y al anterior, permitiendo un recorrido eficiente en ambas direcciones.
- **Flexibilidad en la inserción y eliminación:** Las operaciones de inserción y eliminación de elementos son más versátiles, ya que se pueden realizar eficientemente en cualquier punto de la lista.
- **No requiere espacio adicional para el control de la estructura:** A diferencia de los vectores, las listas doblemente enlazadas no necesitan definir un tamaño inicial, adaptándose dinámicamente a las necesidades de almacenamiento.

## Operaciones Básicas

- **Inserción:** Añadir un nuevo nodo en la lista, ya sea al inicio, al final o en medio de dos nodos existentes.
- **Eliminación:** Eliminar un nodo específico de la lista, ajustando los enlaces de los nodos adyacentes para mantener la integridad de la estructura.
- **Búsqueda:** Localizar un nodo dentro de la lista que cumpla con ciertos criterios.
- **Recorrido:** Acceder secuencialmente a cada uno de los nodos de la lista, ya sea desde el principio hacia el final o viceversa.

## Ventajas y Desventajas

### Ventajas

- **Flexibilidad:** La estructura dinámica de la lista doblemente enlazada permite un manejo eficiente de la memoria, ajustándose al número de elementos almacenados.
- **Eficiencia en operaciones específicas:** Las operaciones de inserción y eliminación son más rápidas comparadas con otras estructuras de datos lineales como los arrays, especialmente cuando se realizan en la mitad de la lista.

### Desventajas

- **Consumo de memoria adicional:** Cada nodo requiere memoria adicional para almacenar dos referencias, lo que incrementa el uso total de memoria en comparación con las listas simplemente enlazadas.
- **Complejidad en la manipulación:** El manejo de dos punteros por nodo puede complicar la implementación de algunas operaciones y aumentar el riesgo de errores, como la corrupción de la estructura de la lista.

En resumen, las listas doblemente enlazadas ofrecen una potente alternativa a las listas simplemente enlazadas y otras estructuras de datos lineales, especialmente en aplicaciones donde las operaciones de inserción y eliminación frecuentes y el recorrido en ambas direcciones son requisitos críticos. Sin embargo, es importante considerar su mayor complejidad y requerimientos de memoria al decidir su uso en un proyecto específico.

Puedes disfrutar de un ejemplo de implementación en estos ficheros [Code1](dll_node.hpp) [Code2](dll.hpp) [Code2](main_dll.cpp)

# Introducción al Tipo Abstracto de Dato Pila (Stack)

## Definición

El **Tipo Abstracto de Dato Pila** (en inglés, *Stack*) es una estructura de datos que permite almacenar y recuperar elementos siguiendo un orden último en entrar, primero en salir (LIFO, por sus siglas en inglés *Last In, First Out*). Esto significa que el último elemento añadido a la pila será el primero en ser retirado.

## Características Principales

- **LIFO**: *Last In, First Out* (último en entrar, primero en salir).
- **Acceso restringido**: Solo se puede acceder al elemento superior de la pila.
- **Operaciones básicas**:
  - `Push`: Añadir un elemento en la cima de la pila.
  - `Pop`: Remover y retornar el elemento de la cima de la pila.
  - `Top` o `Peek`: Observar el elemento de la cima de la pila sin removerlo.
  - `IsEmpty`: Verificar si la pila está vacía.

## Aplicaciones

Las pilas son utilizadas en una amplia variedad de aplicaciones informáticas, incluyendo:

## Aplicaciones más importantes del Tipo Abstracto de Datos Pila (Stack)

### Gestión de llamadas a funciones y procedimientos

- **Descripción**: Las pilas facilitan la gestión de llamadas a funciones o procedimientos, almacenando direcciones de retorno y variables locales. Esto permite ejecuciones anidadas y manejo eficiente de subrutinas.

### Eliminación de la recursividad

- **Descripción**: La recursividad en funciones puede convertirse en iteración mediante pilas, optimizando el uso de memoria y evitando el desbordamiento de pila en casos de recursividad profunda.

### Evaluación y conversión de expresiones

- **Descripción**: Las pilas son esenciales en la evaluación de expresiones aritméticas y lógicas y en su conversión entre notaciones (infija, postfija, prefija). Esto es crucial para compiladores e intérpretes.

### Soporte para operaciones de deshacer (Undo)

- **Descripción**: En aplicaciones de edición y entornos interactivos, las pilas gestionan las operaciones de deshacer, permitiendo revertir acciones almacenando cada acción del usuario.

### Navegación (Forward y Backward) en aplicaciones web y exploradores de archivos

- **Descripción**: Las pilas permiten implementar la navegación hacia adelante y hacia atrás, almacenando las direcciones visitadas o los directorios abiertos, facilitando la navegación por páginas o directorios previos.

### Análisis sintáctico en compiladores

- **Descripción**: El análisis sintáctico en compiladores utiliza pilas para manejar estructuras gramaticales anidadas, verificando la corrección sintáctica del código fuente.

### Manejo de memoria en sistemas operativos

- **Descripción**: Los sistemas operativos usan pilas para gestionar la memoria de los procesos, incluyendo variables locales, direcciones de retorno y el estado del procesador, facilitando la ejecución concurrente de múltiples procesos.


Estas aplicaciones demuestran la importancia y versatilidad del TAD Pila en distintas áreas de la computación, subrayando su capacidad para organizar datos y controlar flujos de ejecución en un modelo LIFO.

## Implementación

Una pila puede ser implementada utilizando diferentes estructuras de datos subyacentes, como arreglos (arrays) o listas enlazadas. La elección de la estructura subyacente puede afectar la eficiencia de las operaciones de la pila. Puedes encontrar código de ejemplo en los siguientes ficheros: [Código 1] (source/vector.h) [Código 2](source/dll.h) [Código 3](source/dll_node.h) [Código 4](source/stack_v.h) [Código 5](source/stack_l.h) [Código 6](source/main_stack.cc) [Código 7](source/parenthesis.cc)


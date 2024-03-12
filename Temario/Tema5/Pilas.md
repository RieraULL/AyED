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

- **Evaluación de expresiones**: Manejo de expresiones aritméticas en notación postfija o infija.
- **Gestión de llamadas a funciones**: Mantenimiento de direcciones de retorno en llamadas a funciones.
- **Algoritmos de recorrido**: Por ejemplo, algoritmos para recorrer estructuras de datos complejas como árboles y grafos.
- **Desarrollo de algoritmos**: Implementación de algoritmos que necesitan revertir secuencias o manejar datos de forma inversa a su orden de entrada.

## Implementación

Una pila puede ser implementada utilizando diferentes estructuras de datos subyacentes, como arreglos (arrays) o listas enlazadas. La elección de la estructura subyacente puede afectar la eficiencia de las operaciones de la pila. Puedes encontrar código de ejemplo en los siguientes ficheros: [Código 1] (source/vector.h) [Código 2](source/dll.h) [Código 3](source/dll_node.h) [Código 4](source/stack_v.h) [Código 5](source/stack_l.h) [Código 6](source/main_stack.cc) [Código 7](source/parenthesis.cc)


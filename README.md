# Algoritmos y Estructuras de Datos

> [!IMPORTANT]
> El material de este repositorio **no constituye** los apuntes oficiales de la asignatura *Algoritmos y Estructuras de Datos* del Grado en Ingeniería Informática (ULL). Su propósito es complementar las clases, la bibliografía y el material referenciado en la guía docente.

## Propósito

- Repositorio de ejemplos y problemas resueltos para apoyar el estudio.
- Referencia rápida de fragmentos de código y patrones básicos en C++.
- Puntos de partida para prácticas guiadas y autoevaluación.

## Requisitos

- Linux o WSL (recomendado) y `bash`.
- Compilador C++ compatible (recomendado `g++` 11+ o `clang++` 13+).

Comprobación rápida:

```bash
g++ --version
clang++ --version
```

## Cómo usar este repositorio

- Navega por los temas y abre los `.md` para leer teoría y consignas.
- Compila y ejecuta los ejemplos de `problemas/` o `Temario/**/source` para afianzar conceptos.
- Modifica el código y experimenta: añade `-Wall -Wextra -pedantic -std=c++17` para mejores diagnósticos.

Ejemplo de compilación y ejecución (Linux):

```bash
cd problemas/prob1
g++ -std=c++17 -O2 -Wall -Wextra -pedantic prob1.cpp -o prob1
./prob1
```

## Índice rápido

- Tema 1
  - [Punteros en C++](Temario/Tema1/punteros/punteros.md)
  - [Clases (visión general)](Temario/Tema1/clases/clases.md)
    - [Declarando una clase](Temario/Tema1/clases/definicion-de-clases.md)
    - [Implementando una clase](Temario/Tema1/clases/implementacion-de-clases.md)
    - [Declarando objetos](Temario/Tema1/clases/declarando-objetos.md)
    - [Invocando métodos](Temario/Tema1/clases/invocando-metodos.md)
    - [Objetos constantes](Temario/Tema1/clases/declarando-objetos-constantes.md)
    - [Objetos dinámicos](Temario/Tema1/clases/objetos-dinamicos.md)
    - [Paso de parámetros](Temario/Tema1/clases/paso-de-parametros.md)
    - [Sobrecarga de operadores](Temario/Tema1/clases/sobrecarga-de-operadores.md)
    - [Herencia](Temario/Tema1/clases/herencia.md)
    - [Plantillas](Temario/Tema1/clases/plantillas.md)
  - [Un ejemplo complejo](Temario/Tema1/un-ejemplo.md)
- Tema 2
  - [Problemas con vectores](Temario/Tema2/problema_vector.md)
  - [Problemas con matrices](Temario/Tema2/matrices.md)
  - [Problemas con vectores dispersos](Temario/Tema2/vectores_dispersos.md)
  - [Merge sort (apuntes)](Temario/Tema2/merge_sort/P3.md)
- Tema 3
  - [TAD Listas simplemente enlazadas](Temario/Tema3/listas/ListasSSL.md)
- Tema 4
  - [TAD Listas doblemente enlazadas](Temario/Tema4/ListasDLL.md)
- Tema 5
  - [TAD Pila](Temario/Tema5/Pilas.md)
- Tema 6
  - [Recursividad](Temario/Tema6/Recursividad.md)
  - [Backtracking](Temario/Tema6/Backtracking.md)
  - [Ejemplos y ejercicios](Temario/Tema6/README.md)

## Exámenes y cursos

- Exámenes y colecciones: `examenes/`
- Material del curso actual: `cursos/2024-2025/`

## Estructura de carpetas

- `problemas/`: enunciados y soluciones mínimas por tema o examen.
- `Temario/`: notas y ejemplos por tema (código de apoyo en subcarpetas `source/`, `code/`, etc.).

## Consejos de estudio

- Lee el enunciado, intenta una solución propia y luego contrasta con la propuesta.
- Añade pruebas pequeñas para cada función (entradas límite y casos de error).
- Mide complejidad temporal y espacial cuando sea relevante.

## Contribuir

- Sugerencias, erratas o mejoras: abre un Issue o Pull Request.
- Estilo recomendado: C++17, warnings activados, funciones y clases autoexplicativas.

## Apéndice: Problemas de examen

### Colecciones generales

#### [Problemas de examen resueltos I](examenes/colecciones/Problemas1.md)

1. Producto escalar de vectores
2. Conteo de ocurrencias con tolerancia
3. Elementos menores/mayores con tolerancia
4. Suma y conteo de pares/impares
5. Mover máximo a posición final
6. Ordenamiento por burbuja (bubble sort)
7. Contenedor ordenado con vector
8. Cola basada en lista enlazada
9. Número en base arbitraria con operaciones

#### [Problemas de examen resueltos II](examenes/colecciones/Problemas2.md)

1. Clases `point_t` y `line_equ_t` - Geometría euclídea
2. Clase `vector_t` con límites izquierdo y derecho
3. Triángulo de Pascal y números combinatorios

### Problemas por estructura de datos

#### [Listas enlazadas](examenes/Listas/)

- Implementación de lista simplemente enlazada
- Operaciones básicas: inserción, eliminación, búsqueda
- Archivos: `main_sll.cpp`, `sll_t.hpp`, `sll_node_t.hpp`

#### [Matrices](examenes/Matrices/)

- Operaciones con matrices
- Archivos: `matrices.cpp`, `matrix_t.hpp`

#### [Pilas](examenes/Pilas/)

- Verificación de paréntesis balanceados
- Archivo: `check_bracket.cpp`

#### [Recursividad](examenes/Recursividad/)

- Problemas resueltos con técnicas recursivas
- Archivo: `Recursividad.cpp`

## Licencia y créditos

- Licencia: ver `LICENSE`.
- Autores:
  - Jorge Riera Ledesma <jriera@ull.es>
  - Marcos A. Colebrook Santamaría <mcolesan@ull.es>
  - Patricio García Báez <pgarcia@ull.es>




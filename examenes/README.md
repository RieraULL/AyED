# Exámenes y problemas resueltos

Este directorio contiene problemas de examen resueltos organizados por tema y colecciones generales.

## Contenido

### Colecciones generales

- [Problemas de examen resueltos I](colecciones/Problemas1.md) - Vectores, funciones básicas, algoritmos de ordenación
- [Problemas de examen resueltos II](colecciones/Problemas2.md) - Clases, geometría, números combinatorios

### Problemas por tema

- **[Listas](Listas/)** - Ejercicios sobre listas simplemente enlazadas
- **[Matrices](Matrices/)** - Ejercicios sobre matrices y operaciones bidimensionales
- **[Pilas](Pilas/)** - Ejercicios sobre el TAD Pila
- **[Recursividad](Recursividad/)** - Ejercicios sobre técnicas recursivas

## Cómo usar este material

1. **Lee el enunciado** con atención antes de mirar la solución.
2. **Intenta resolver** el problema por tu cuenta.
3. **Contrasta** tu solución con la propuesta.
4. **Compila y ejecuta** el código para verificar su funcionamiento.

## Compilación

Para compilar los ejemplos, usa:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic archivo.cpp -o ejecutable
```

O si existe un `Makefile` en el directorio:

```bash
make
```

## Consejos para el examen

- Practica la escritura de código sin IDE (papel o editor simple).
- Asegúrate de entender la complejidad temporal y espacial de tus soluciones.
- Revisa los casos límite (vectores vacíos, valores nulos, etc.).
- Conoce bien las estructuras de datos básicas y sus operaciones.

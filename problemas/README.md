# Problemas - Soluciones de código

Este directorio contiene implementaciones de soluciones a problemas resueltos.

## Estructura

- **prob1/** - Problemas básicos con vectores, funciones y algoritmos
- **prob2/** - Problemas con clases (geometría, estructuras avanzadas)

## Compilación rápida

Cada carpeta incluye un `Makefile` para compilar fácilmente:

```bash
cd prob1
make          # Compila todos los problemas
make prob1    # Compila solo prob1
make clean    # Limpia ejecutables
```

## Compilación manual

Si prefieres compilar manualmente:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -pedantic archivo.cpp -o ejecutable
```

## Contenido por carpeta

### prob1/

Problemas básicos con vectores y funciones:

- `prob1.cpp` - Producto escalar
- `prob2.cpp` - Conteo con tolerancia
- `prob3.cpp` - Comparaciones con tolerancia
- `prob4.cpp` - Suma y conteo par/impar
- `prob5.cpp` - Mover máximo a posición
- `prob6.cpp` - Contenedor ordenado
- `prob8.cpp` - Cola con lista enlazada
- `prob9.cpp` - Número en base arbitraria

### prob2/

Problemas con clases:

- `prob1.cpp` + `point_t.hpp` + `line_eq_t.hpp` - Geometría (punto y recta)
- `bounded_vector.cpp` - Vector con límites
- `pascal.cpp` - Triángulo de Pascal
- `rational.cpp` - Números racionales

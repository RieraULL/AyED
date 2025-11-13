# Makefile para compilar problemas de examen resueltos II
# Uso: make [target]

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic
TARGETS = prob1 bounded_vector pascal rational

.PHONY: all clean

all: $(TARGETS)

prob1: prob1.cpp point_t.hpp line_eq_t.hpp
	$(CXX) $(CXXFLAGS) prob1.cpp -o $@

bounded_vector: bounded_vector.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

pascal: pascal.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

rational: rational.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

# Ayuda
help:
	@echo "Targets disponibles:"
	@echo "  all             - Compila todos los problemas"
	@echo "  prob1           - Compila problema 1 (punto y recta)"
	@echo "  bounded_vector  - Compila problema 2 (vector acotado)"
	@echo "  pascal          - Compila problema 3 (triángulo de Pascal)"
	@echo "  rational        - Compila números racionales"
	@echo "  clean           - Elimina ejecutables"
	@echo "  help            - Muestra esta ayuda"

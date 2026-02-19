# Makefile para ejemplos de Recursividad y Backtracking
# Uso: make [target]

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic

# Programas de recursividad
RECURSION_PROGS = factorial_fibonacci torres_hanoi

# Programas de backtracking
BACKTRACK_PROGS = permutaciones n_reinas subset_sum

# Todos los programas
ALL_PROGS = $(RECURSION_PROGS) $(BACKTRACK_PROGS)

.PHONY: all recursion backtracking clean help

all: $(ALL_PROGS)

recursion: $(RECURSION_PROGS)

backtracking: $(BACKTRACK_PROGS)

# Recursividad
factorial_fibonacci: factorial_fibonacci.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

torres_hanoi: torres_hanoi.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Backtracking
permutaciones: permutaciones.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

n_reinas: n_reinas.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

subset_sum: subset_sum.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(ALL_PROGS)

help:
	@echo "Targets disponibles:"
	@echo "  all             - Compila todos los ejemplos"
	@echo "  recursion       - Compila solo ejemplos de recursividad"
	@echo "  backtracking    - Compila solo ejemplos de backtracking"
	@echo "  clean           - Elimina ejecutables"
	@echo "  help            - Muestra esta ayuda"
	@echo ""
	@echo "Ejemplos de recursividad:"
	@echo "  - factorial_fibonacci: Factorial, Fibonacci, potencia, MCD"
	@echo "  - torres_hanoi: Torres de Hanoi"
	@echo ""
	@echo "Ejemplos de backtracking:"
	@echo "  - permutaciones: Genera todas las permutaciones"
	@echo "  - n_reinas: Problema de las N reinas"
	@echo "  - subset_sum: Suma de subconjuntos"

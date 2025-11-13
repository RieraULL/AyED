# Makefile para compilar problemas de examen resueltos I
# Uso: make [target]

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra -pedantic
TARGETS = prob1 prob2 prob3 prob4 prob5 prob6 prob8 prob9

.PHONY: all clean

all: $(TARGETS)

prob1: prob1.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

prob2: prob2.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

prob3: prob3.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

prob4: prob4.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

prob5: prob5.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

prob6: prob6.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

prob8: prob8.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

prob9: prob9.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)

# Ayuda
help:
	@echo "Targets disponibles:"
	@echo "  all       - Compila todos los problemas"
	@echo "  prob1-9   - Compila problema específico"
	@echo "  clean     - Elimina ejecutables"
	@echo "  help      - Muestra esta ayuda"

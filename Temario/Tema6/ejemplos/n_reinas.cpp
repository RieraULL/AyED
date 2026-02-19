// Backtracking: N-Reinas
// Compilar: g++ -std=c++17 -Wall -Wextra -pedantic n_reinas.cpp -o n_reinas

#include <iostream>
#include <vector>
#include <cmath>

class NReinas {
private:
    int n;
    std::vector<int> tablero;
    int soluciones;
    
    bool es_seguro(int fila, int col) {
        for (int i = 0; i < fila; i++) {
            if (tablero[i] == col) return false;
            if (std::abs(tablero[i] - col) == std::abs(i - fila)) {
                return false;
            }
        }
        return true;
    }
    
    void imprimir_tablero() {
        std::cout << "\nSolución #" << soluciones << ":" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tablero[i] == j) {
                    std::cout << " Q ";
                } else {
                    std::cout << " . ";
                }
            }
            std::cout << std::endl;
        }
    }
    
    void resolver_rec(int fila) {
        if (fila == n) {
            soluciones++;
            imprimir_tablero();
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (es_seguro(fila, col)) {
                tablero[fila] = col;
                resolver_rec(fila + 1);
            }
        }
    }
    
public:
    NReinas(int size) : n(size), tablero(size), soluciones(0) {}
    
    void resolver() {
        std::cout << "Resolviendo problema de " << n << " reinas..." << std::endl;
        resolver_rec(0);
        std::cout << "\n=== Total de soluciones: " << soluciones << " ===" << std::endl;
    }
};

int main() {
    int n;
    std::cout << "=== Problema de las N-Reinas ===" << std::endl;
    std::cout << "Ingrese N (tamaño del tablero): ";
    std::cin >> n;
    
    if (n < 1 || n > 10) {
        std::cout << "Por favor, ingrese un valor entre 1 y 10." << std::endl;
        return 1;
    }
    
    NReinas problema(n);
    problema.resolver();
    
    return 0;
}

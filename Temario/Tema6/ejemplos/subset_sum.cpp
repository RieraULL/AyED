// Backtracking: Suma de subconjuntos (Subset Sum)
// Compilar: g++ -std=c++17 -Wall -Wextra -pedantic subset_sum.cpp -o subset_sum

#include <iostream>
#include <vector>

int soluciones_encontradas = 0;

void imprimir_subconjunto(const std::vector<int>& subset) {
    std::cout << "{ ";
    for (size_t i = 0; i < subset.size(); i++) {
        std::cout << subset[i];
        if (i < subset.size() - 1) std::cout << ", ";
    }
    std::cout << " }";
}

void encontrar_subconjuntos(const std::vector<int>& arr,
                            std::vector<int>& solucion,
                            int indice,
                            int suma_actual,
                            int objetivo) {
    // Caso base: encontramos una solución
    if (suma_actual == objetivo) {
        soluciones_encontradas++;
        std::cout << "Solución #" << soluciones_encontradas << ": ";
        imprimir_subconjunto(solucion);
        std::cout << " (suma = " << objetivo << ")" << std::endl;
        return;
    }
    
    // Poda: nos pasamos o no hay más elementos
    if (suma_actual > objetivo || indice >= arr.size()) {
        return;
    }
    
    // Opción 1: incluir elemento actual
    solucion.push_back(arr[indice]);
    encontrar_subconjuntos(arr, solucion, indice + 1, 
                          suma_actual + arr[indice], objetivo);
    solucion.pop_back();  // Backtrack
    
    // Opción 2: no incluir elemento actual
    encontrar_subconjuntos(arr, solucion, indice + 1, 
                          suma_actual, objetivo);
}

int main() {
    std::cout << "=== Problema de Suma de Subconjuntos ===" << std::endl;
    
    // Conjunto de ejemplo
    std::vector<int> arr = {3, 34, 4, 12, 5, 2};
    int objetivo = 9;
    
    std::cout << "Conjunto: { ";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) std::cout << ", ";
    }
    std::cout << " }" << std::endl;
    std::cout << "Objetivo: " << objetivo << std::endl << std::endl;
    
    std::vector<int> solucion;
    encontrar_subconjuntos(arr, solucion, 0, 0, objetivo);
    
    if (soluciones_encontradas == 0) {
        std::cout << "No se encontraron soluciones." << std::endl;
    } else {
        std::cout << "\nTotal de soluciones: " << soluciones_encontradas << std::endl;
    }
    
    return 0;
}

// Backtracking: Permutaciones
// Compilar: g++ -std=c++17 -Wall -Wextra -pedantic permutaciones.cpp -o permutaciones

#include <iostream>
#include <vector>
#include <algorithm>

int contador = 0;

void imprimir_vector(const std::vector<int>& v) {
    std::cout << "{ ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i < v.size() - 1) std::cout << ", ";
    }
    std::cout << " }";
}

void permutar(std::vector<int>& arr, int inicio) {
    if (inicio == arr.size()) {
        contador++;
        std::cout << contador << ": ";
        imprimir_vector(arr);
        std::cout << std::endl;
        return;
    }
    
    for (int i = inicio; i < arr.size(); i++) {
        std::swap(arr[inicio], arr[i]);
        permutar(arr, inicio + 1);
        std::swap(arr[inicio], arr[i]);  // Backtrack
    }
}

int main() {
    int n;
    std::cout << "=== Generador de Permutaciones ===" << std::endl;
    std::cout << "¿Cuántos elementos? ";
    std::cin >> n;
    
    if (n <= 0 || n > 10) {
        std::cout << "Por favor, ingrese un número entre 1 y 10." << std::endl;
        return 1;
    }
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    std::cout << std::endl << "Permutaciones de ";
    imprimir_vector(arr);
    std::cout << ":" << std::endl << std::endl;
    
    permutar(arr, 0);
    
    std::cout << std::endl << "Total: " << contador << " permutaciones" << std::endl;
    
    return 0;
}

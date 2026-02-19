// Torres de Hanoi
// Compilar: g++ -std=c++17 -Wall -Wextra -pedantic torres_hanoi.cpp -o torres_hanoi

#include <iostream>
#include <string>

int movimientos = 0;

void hanoi(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        movimientos++;
        std::cout << "Movimiento " << movimientos << ": "
                  << "Mover disco 1 de " << origen 
                  << " a " << destino << std::endl;
        return;
    }
    
    // Mover n-1 discos de origen a auxiliar usando destino
    hanoi(n - 1, origen, auxiliar, destino);
    
    // Mover el disco más grande de origen a destino
    movimientos++;
    std::cout << "Movimiento " << movimientos << ": "
              << "Mover disco " << n << " de " << origen 
              << " a " << destino << std::endl;
    
    // Mover n-1 discos de auxiliar a destino usando origen
    hanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int n;
    std::cout << "=== Torres de Hanoi ===" << std::endl;
    std::cout << "Ingrese el número de discos: ";
    std::cin >> n;
    
    if (n <= 0) {
        std::cout << "Número de discos inválido." << std::endl;
        return 1;
    }
    
    std::cout << std::endl << "Solución:" << std::endl;
    hanoi(n, 'A', 'C', 'B');
    
    std::cout << std::endl << "Total de movimientos: " << movimientos << std::endl;
    std::cout << "Número mínimo teórico: " << (1 << n) - 1 << std::endl;
    
    return 0;
}

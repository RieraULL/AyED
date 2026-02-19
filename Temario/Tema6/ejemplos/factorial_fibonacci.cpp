// Ejemplos básicos de recursividad
// Compilar: g++ -std=c++17 -Wall -Wextra -pedantic factorial_fibonacci.cpp -o factorial_fibonacci

#include <iostream>
#include <iomanip>

// Factorial recursivo
unsigned long factorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Fibonacci recursivo (versión simple, no optimizada)
unsigned long fibonacci(unsigned int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Potencia recursiva
long long potencia(int base, unsigned int exponente) {
    if (exponente == 0) return 1;
    if (exponente == 1) return base;
    return base * potencia(base, exponente - 1);
}

// Suma de dígitos
int suma_digitos(int n) {
    if (n == 0) return 0;
    return (n % 10) + suma_digitos(n / 10);
}

// MCD (Máximo Común Divisor) - Algoritmo de Euclides
int mcd(int a, int b) {
    if (b == 0) return a;
    return mcd(b, a % b);
}

int main() {
    std::cout << "=== Ejemplos de Recursividad ===" << std::endl << std::endl;
    
    // Factorial
    std::cout << "Factorial:" << std::endl;
    for (int i = 0; i <= 10; i++) {
        std::cout << std::setw(2) << i << "! = " 
                  << std::setw(10) << factorial(i) << std::endl;
    }
    std::cout << std::endl;
    
    // Fibonacci
    std::cout << "Serie de Fibonacci:" << std::endl;
    for (int i = 0; i < 15; i++) {
        std::cout << "F(" << std::setw(2) << i << ") = " 
                  << std::setw(5) << fibonacci(i) << std::endl;
    }
    std::cout << std::endl;
    
    // Potencia
    std::cout << "Potencias:" << std::endl;
    std::cout << "2^10 = " << potencia(2, 10) << std::endl;
    std::cout << "3^5 = " << potencia(3, 5) << std::endl;
    std::cout << "5^3 = " << potencia(5, 3) << std::endl;
    std::cout << std::endl;
    
    // Suma de dígitos
    std::cout << "Suma de dígitos:" << std::endl;
    int nums[] = {123, 9876, 555, 1024};
    for (int num : nums) {
        std::cout << "Suma dígitos de " << num << " = " 
                  << suma_digitos(num) << std::endl;
    }
    std::cout << std::endl;
    
    // MCD
    std::cout << "Máximo Común Divisor:" << std::endl;
    std::cout << "MCD(48, 18) = " << mcd(48, 18) << std::endl;
    std::cout << "MCD(100, 75) = " << mcd(100, 75) << std::endl;
    std::cout << "MCD(17, 19) = " << mcd(17, 19) << std::endl;
    
    return 0;
}

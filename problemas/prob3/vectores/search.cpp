#include "vector.hpp"

#include <iomanip>
#include <iostream>
#include <random>
#include <cmath>
#include <vector>

using namespace std;

bool sonIguales(const double a, const double b, const double tolerancia) {
    return fabs(a - b) <= tolerancia;
}

bool busquedaSecuencialOrdenada(const AyED::vector &v, double objetivo, long long &iteraciones,
                                double tolerancia = 1e-9) {
    iteraciones = 0;
    bool encontrado = false;
    bool detener = false;
    size_t i = 0;

    while (i < v.size() && !encontrado && !detener) {
        ++iteraciones;

        if (sonIguales(v[i], objetivo, tolerancia)) {
            encontrado = true;
        } else {
            if (v[i] > objetivo + tolerancia) {
                detener = true;
            } else {
                ++i;
            }
        }
    }

    return encontrado;
}

bool busquedaBinaria(const AyED::vector &v, double objetivo, long long &iteraciones,
                     double tolerancia = 1e-9) {
    iteraciones = 0;
    int izquierda = 0;
    int derecha = static_cast<int>(v.size()) - 1;
    bool encontrado = false;

    while (izquierda <= derecha && !encontrado) {
        ++iteraciones;
        int medio = izquierda + (derecha - izquierda) / 2;

        if (sonIguales(v[medio], objetivo, tolerancia)) {
            encontrado = true;
        } else {
            if (v[medio] < objetivo - tolerancia) {
                izquierda = medio + 1;
            } else {
                derecha = medio - 1;
            }
        }
    }

    return encontrado;
}

void busquedaSecuencialOrdenadaPosiciones(const AyED::vector &v, double objetivo, vector<int> &posiciones,
                                          double tolerancia = 1e-9) {
    posiciones.clear();
    bool detener = false;
    size_t i = 0;

    while (i < v.size() && !detener) {
        if (sonIguales(v[i], objetivo, tolerancia)) {
            posiciones.push_back(static_cast<int>(i));
            ++i;
        } else {
            if (v[i] > objetivo + tolerancia) {
                detener = true;
            } else {
                ++i;
            }
        }
    }
}

void busquedaBinariaPosiciones(const AyED::vector &v, double objetivo, vector<int> &posiciones,
                               double tolerancia = 1e-9) {
    posiciones.clear();
    int izquierda = 0;
    int derecha = static_cast<int>(v.size()) - 1;
    int posicionEncontrada = -1;

    while (izquierda <= derecha && posicionEncontrada == -1) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (sonIguales(v[medio], objetivo, tolerancia)) {
            posicionEncontrada = medio;
        } else {
            if (v[medio] < objetivo - tolerancia) {
                izquierda = medio + 1;
            } else {
                derecha = medio - 1;
            }
        }
    }

    if (posicionEncontrada == -1) {
        return;
    }

    int primera = posicionEncontrada;
    int ultima = posicionEncontrada;

    while (primera > 0 && sonIguales(v[primera - 1], objetivo, tolerancia)) {
        --primera;
    }

    while (ultima + 1 < static_cast<int>(v.size()) && sonIguales(v[ultima + 1], objetivo, tolerancia)) {
        ++ultima;
    }

    posiciones.reserve(ultima - primera + 1);
    for (int i = primera; i <= ultima; ++i) {
        posiciones.push_back(i);
    }
}

void generarVectorOrdenadoAleatorio(AyED::vector &v, mt19937 &gen) {
    uniform_int_distribution<int> inicioDist(0, 100);
    uniform_int_distribution<int> saltoDist(1, 5);

    double valorActual = static_cast<double>(inicioDist(gen) * 2);

    for (size_t i = 0; i < v.size(); ++i) {
        double salto = static_cast<double>(saltoDist(gen) * 2);
        valorActual += salto;
        v[i] = valorActual;
    }
}

int main() {
    const int TAM = 65536;
    const int REPETICIONES = 40;

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> indiceDist(0, TAM - 1);
    uniform_int_distribution<int> modoBusquedaDist(0, 1); // 0: existente, 1: no existente

    AyED::vector v(TAM);

    long long sumaSecuencial = 0;
    long long sumaBinaria = 0;

    long long sumaSecuencialExistente = 0;
    long long sumaBinariaExistente = 0;
    int casosExistentes = 0;

    long long sumaSecuencialNoExistente = 0;
    long long sumaBinariaNoExistente = 0;
    int casosNoExistentes = 0;

    cout << "Comparacion de iteraciones en vector ordenado (N = " << TAM << ")\n";
    cout << "Repeticiones: " << REPETICIONES << "\n\n";
    cout << left << setw(8) << "Prueba" << setw(12) << "Objetivo" << setw(14) << "Secuencial"
         << setw(10) << "Binaria" << "Encontrado\n";
    cout << string(56, '-') << "\n";

    for (int r = 1; r <= REPETICIONES; ++r) {
        generarVectorOrdenadoAleatorio(v, gen);

        double objetivo;
        bool deberiaExistir;

        if (modoBusquedaDist(gen) == 0) {
            int indice = indiceDist(gen);
            objetivo = v[indice];
            deberiaExistir = true;
            ++casosExistentes;
        } else {
            int minimo = static_cast<int>(v[0]) - 1;
            int maximo = static_cast<int>(v[TAM - 1]) + 1;
            uniform_int_distribution<int> objetivoDist(minimo, maximo);
            objetivo = static_cast<double>(objetivoDist(gen));
            objetivo = 2.0 * objetivo + 1.0; // fuerza impar: el vector contiene solo pares
            deberiaExistir = false;
            ++casosNoExistentes;
        }

        long long iterSecuencial = 0;
        long long iterBinaria = 0;

        bool encontradoSecuencial = busquedaSecuencialOrdenada(v, objetivo, iterSecuencial);
        bool encontradoBinaria = busquedaBinaria(v, objetivo, iterBinaria);

        sumaSecuencial += iterSecuencial;
        sumaBinaria += iterBinaria;

        if (deberiaExistir) {
            sumaSecuencialExistente += iterSecuencial;
            sumaBinariaExistente += iterBinaria;
        } else {
            sumaSecuencialNoExistente += iterSecuencial;
            sumaBinariaNoExistente += iterBinaria;
        }

        cout << left << setw(8) << r << setw(12) << objetivo << setw(14) << iterSecuencial
             << setw(10) << iterBinaria << (encontradoSecuencial ? "SI" : "NO") << "\n";

        if (encontradoSecuencial != encontradoBinaria) {
            cout << "ADVERTENCIA: discrepancia entre algoritmos en la prueba " << r << "\n";
        }
    }

    cout << "\n";
    cout << "Promedio iteraciones (global):\n";
    cout << "- Secuencial: " << static_cast<double>(sumaSecuencial) / REPETICIONES << "\n";
    cout << "- Binaria:    " << static_cast<double>(sumaBinaria) / REPETICIONES << "\n\n";

    if (casosExistentes > 0) {
        cout << "Promedio con objetivo EXISTENTE:\n";
        cout << "- Secuencial: " << static_cast<double>(sumaSecuencialExistente) / casosExistentes << "\n";
        cout << "- Binaria:    " << static_cast<double>(sumaBinariaExistente) / casosExistentes << "\n\n";
    }

    if (casosNoExistentes > 0) {
        cout << "Promedio con objetivo NO EXISTENTE:\n";
        cout << "- Secuencial: " << static_cast<double>(sumaSecuencialNoExistente) / casosNoExistentes << "\n";
        cout << "- Binaria:    " << static_cast<double>(sumaBinariaNoExistente) / casosNoExistentes << "\n";
    }

    return 0;
}
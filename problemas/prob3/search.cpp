#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

bool busquedaSecuencialOrdenada(const vector<int> &v, int objetivo, long long &iteraciones) {
    iteraciones = 0;
    bool encontrado = false;
    bool detener = false;
    size_t i = 0;

    while (i < v.size() && !encontrado && !detener) {
        ++iteraciones;

        if (v[i] == objetivo) {
            encontrado = true;
        } else {
            if (v[i] > objetivo) {
                detener = true;
            } else {
                ++i;
            }
        }
    }

    return encontrado;
}

bool busquedaBinaria(const vector<int> &v, int objetivo, long long &iteraciones) {
    iteraciones = 0;
    int izquierda = 0;
    int derecha = static_cast<int>(v.size()) - 1;
    bool encontrado = false;

    while (izquierda <= derecha && !encontrado) {
        ++iteraciones;
        int medio = izquierda + (derecha - izquierda) / 2;

        if (v[medio] == objetivo) {
            encontrado = true;
        } else {
            if (v[medio] < objetivo) {
                izquierda = medio + 1;
            } else {
                derecha = medio - 1;
            }
        }
    }

    return encontrado;
}

void generarVectorOrdenadoAleatorio(vector<int> &v, mt19937 &gen) {
    uniform_int_distribution<int> inicioDist(0, 100);
    uniform_int_distribution<int> saltoDist(1, 5);

    int valorActual = inicioDist(gen) * 2;

    for (size_t i = 0; i < v.size(); ++i) {
        int salto = saltoDist(gen) * 2;
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

    vector<int> v(TAM);

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

        int objetivo;
        bool deberiaExistir;

        if (modoBusquedaDist(gen) == 0) {
            int indice = indiceDist(gen);
            objetivo = v[indice];
            deberiaExistir = true;
            ++casosExistentes;
        } else {
            int minimo = v.front() - 1;
            int maximo = v.back() + 1;
            uniform_int_distribution<int> objetivoDist(minimo, maximo);
            objetivo = objetivoDist(gen);
            objetivo |= 1; // fuerza impar: el vector contiene solo pares
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
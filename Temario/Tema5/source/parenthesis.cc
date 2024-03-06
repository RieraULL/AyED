// AUTOR: Patricio García
// FECHA: 14/05/20201
// EMAIL: pgarcia@ull.es 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS: Comprueba si en una cadena los paréntesis de distinto
//              tipo ('()[]{}') están balanceados
// REFERENCIA:
//   https://avikdas.com/2020/01/28/the-balanced-parentheses-problem.html
// COMPILACIÓN: g++ -g parenthesis.cc -o parenthesis
// EJECUCIÓN:
//   Balanceadas:
//     ./parenthesis "([4 + 3] * 5 - 1) / 2 + 1"
//     ./parenthesis "([4 + 3] * (5 - 1) / 2) + 1"
//   No balanceadas:
//     ./parenthesis "([4 + 3) * 5 - 1) / 2 + 1"
//     ./parenthesis "([4 + 3] * 5 - 1) / 2) + 1"
//     ./parenthesis "([4 + 3] * 5 - 1 / 2"

#include <iostream>
#include <string.h>

#include "stack_v_t.h"
#include "stack_l_t.h"

using namespace std;

int main(int argc, char *argv[]) {
  stack_v_t<char> pila;
  // stack_l_t<char> pila;
  const char *open_parenths{"([{"};
  const char *closed_parenths{")]}"};

  if (argc == 2) {
    bool fail{false};
    int i{0};
    // Revisar toda la cadena o hasta encontrar un error
    while (argv[1][i] != '\0' && fail != true) {
      if (strchr(open_parenths, argv[1][i]) != NULL)
	pila.push(argv[1][i]);  // Insertar en pila paréntesis abierto
      else if (strchr(closed_parenths, argv[1][i]) != NULL) {
	// Encontrado paréntesis cerrado
	// Hallar posición dentro del string del paréntesis cerrado
	int pos = strchr(closed_parenths, argv[1][i]) - closed_parenths;
	if (pila.empty() || pila.top() != open_parenths[pos])
	  // Si la pila está vacía o no empareja paréntesis fallar
	  fail = true;
        else
	  pila.pop();  // Sacar de pila el paréntesis abierto del top
      }
      // cout << "Caracter: " << argv[1][i] << endl;
      // pila.write();
      i++;
    }
    // Si no habido fallo y la pila esta vacía => bien balanceada
    if (!fail && pila.empty())
      cout << "Cadena  balanceada" << endl;
    else
      cout << "Cadena no balanceada" << endl;
  } else
    cout << "Argumento de entrada incorrecto" << endl;

  return 0;
}

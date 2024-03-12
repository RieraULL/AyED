// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS:
// COMPILACIÓN: g++ -g main_stack.cc -o main_stack
// EJECUCIÓN: ./main_stack

#include <iostream>

#include "stack_v.h"
#include "stack_l.h"

using namespace std;

int main(void)
{
  AyED::stack_v<char> pila_vector;
  cout << "********** PILA VECTOR **********" << endl;
  for (int i = 0; i < 10; i++)
  {
    pila_vector.push('a' + i);
    pila_vector.write();
    cout << endl;
  }
  cout << endl;

  while (!pila_vector.empty())
  {
    pila_vector.pop();
    pila_vector.write();
    cout << endl;
  }

  AyED::stack_l<char> pila_lista;
  cout << "********** PILA LISTA **********" << endl;
  for (int i = 0; i < 10; i++)
  {
    pila_lista.push('a' + i);
    pila_lista.write();
    cout << endl;
  }
  cout << endl;

  while (!pila_lista.empty())
  {
    pila_lista.pop();
    pila_lista.write();
    cout << endl;
  }

  return 0;
}

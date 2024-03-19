// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef STACKL_H_H_
#define STACKL_H_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll.h"

namespace AyED
{

  // Clase para pilas mediante estructura dinámica
  template <class T>
  class stack_l_h : private dll<T>
  {
  public:
    // constructor
    stack_l_h(void) : dll<T>() {}

    // destructor
    ~stack_l_h(void) {}

    // operaciones
    void push(const T &);
    void pop(void);
    const T &top(void) const;
    bool empty(void) const;

    // E/S
    std::ostream &write(std::ostream &os = std::cout) const;
  };

  // operaciones
  template <class T>
  void stack_l_h<T>::push(const T &dato)
  {
    dll_node<T> *nodo = new dll_node<T>(dato);
    assert(nodo != NULL);
    dll<T>::push_front(nodo);
  }

  template <class T>
  void stack_l_h<T>::pop(void)
  {
    assert(!empty());
    delete dll<T>::pop_front();
  }

  template <class T>
  const T &stack_l_h<T>::top(void) const
  {
    assert(!empty());
    return dll<T>::get_head()->get_data();
  }

  template <class T>
  bool stack_l_h<T>::empty(void) const
  {
    return dll<T>::empty();
  }

  // E/S
  template <class T>
  std::ostream &stack_l_h<T>::write(std::ostream &os) const
  {
    dll_node<T> *aux = dll<T>::get_head();
    while (aux != NULL)
    {
      os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
      aux = aux->get_next();
    }
    os << " └─────┘" << std::endl;
    return os;
  }
}

#endif // STACKL_H_H_

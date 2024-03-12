// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef STACKL_H_
#define STACKL_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "dll.h"

namespace AyED
{

  // Clase para pilas mediante estructura dinámica
  template <class T>
  class stack_l
  {
  public:
    // constructor
    stack_l(void) : l_() {}

    // destructor
    ~stack_l(void) {}

    // operaciones
    void push(const T &);
    void pop(void);
    const T &top(void) const;
    bool empty(void) const;

    // E/S
    std::ostream &write(std::ostream &os = std::cout) const;

  private:
    dll<T> l_;
  };

  // operaciones
  template <class T>
  void stack_l<T>::push(const T &dato)
  {
    dll_node<T> *nodo = new dll_node<T>(dato);
    assert(nodo != NULL);
    l_.push_front(nodo);
  }

  template <class T>
  void stack_l<T>::pop(void)
  {
    assert(!empty());
    delete l_.pop_front();
  }

  template <class T>
  const T &stack_l<T>::top(void) const
  {
    assert(!empty());
    return l_.get_head()->get_data();
  }

  template <class T>
  bool stack_l<T>::empty(void) const
  {
    return l_.empty();
  }

  // E/S
  template <class T>
  std::ostream &stack_l<T>::write(std::ostream &os) const
  {
    dll_node<T> *aux = l_.get_head();
    while (aux != NULL)
    {
      os << " │ " << std::setw(2) << aux->get_data() << "  │" << std::endl;
      aux = aux->get_next();
    }
    os << " └─────┘" << std::endl;
    return os;
  }
}

#endif // STACKL_H_

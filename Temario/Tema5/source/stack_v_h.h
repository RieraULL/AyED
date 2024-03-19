// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 5
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef STACKV_H_H_
#define STACKV_H_H_

#include <iostream>
#include <iomanip>
#include <cassert>

#include "vector.h"

#define MAX_STACK_SIZE 20

namespace AyED
{

  // Clase para pilas mediante estructura estática
  template <class T>
  class stack_v_h: private vector<T>
  {
  public:
    // constructores
    stack_v_h(int max_sz) : vector<T>(max_sz), top_(-1) {}
    stack_v_h(void) : vector<T>(MAX_STACK_SIZE), top_(-1) {}

    // destructor
    ~stack_v_h(void) {}

    // operaciones
    void push(const T &dato);
    void pop(void);
    const T &top(void) const;
    bool empty(void) const;
    bool full(void) const;

    // E/S
    std::ostream &write(std::ostream & = std::cout) const;

  private:
    int top_;
  };

  // operaciones
  template <class T>
  void stack_v_h<T>::push(const T &dato)
  {
    assert(!full());
    vector<T>::at(++top_) = dato;
  }

  template <class T>
  void stack_v_h<T>::pop(void)
  {
    assert(!empty());
    top_--;
  }

  template <class T>
  const T &stack_v_h<T>::top(void) const
  {
    assert(!empty());
    return at(top_);
  }

  template <class T>
  bool stack_v_h<T>::empty(void) const
  {
    return (top_ < 0);
  }

  template <class T>
  bool stack_v_h<T>::full(void) const
  {
    return (top_ == vector<T>::get_size() - 1);
  }

  // E/S
  template <class T>
  std::ostream &stack_v_h<T>::write(std::ostream &os) const
  {
    for (int i = top_; i >= 0; i--)
      os << " │ " << std::setw(2) << vector<T>::at(i) << "  │" << std::endl;
    os << " └─────┘" << std::endl;
    return os;
  }

}

#endif // STACKV_H_H_

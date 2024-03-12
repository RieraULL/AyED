// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef DLL_NODET_H_
#define DLL_NODET_H_

#include <iostream>

namespace AyED
{

  // Clase para nodos de listas doblemente enlazadas
  template <class T>
  class dll_node
  {
  public:
    // constructores
    dll_node() : prev_(NULL), data_(), next_(NULL) {} // por defecto
    dll_node(const T &data) : prev_(NULL), data_(data), next_(NULL) {}

    // destructor
    ~dll_node(void) {}

    // getters & setters
    dll_node<T> *get_next(void) const { return next_; }
    void set_next(dll_node<T> *next) { next_ = next; }

    dll_node<T> *get_prev(void) const { return prev_; }
    void set_prev(dll_node<T> *prev) { prev_ = prev; }

    const T &get_data(void) const { return data_; }
    void set_data(const T &data) { data_ = data; }

    // E/S
    std::ostream &write(std::ostream & = std::cout) const;

  private:
    dll_node<T> *prev_;
    T data_;
    dll_node<T> *next_;
  };

  // E/S
  template <class T>
  std::ostream &dll_node<T>::write(std::ostream &os) const
  {
    os << data_;
    return os;
  }
}
#endif // DLL_NODET_H_

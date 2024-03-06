// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 3.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS: 

#ifndef SLL_NODET_H_
#define SLL_NODET_H_

#include <iostream>

// Clase para nodos de listas enlazadas
template <class T> class sll_node_t {
 public:
  // constructores
  sll_node_t(void) : data_(), next_(NULL) {}  // constructor por defecto
  sll_node_t(const T& data) : data_(data), next_(NULL) {} // constructor

  // destructor
  ~sll_node_t(void) {};

  // getters & setters
  sll_node_t<T>* get_next(void) const { return next_; }
  void set_next(sll_node_t<T>* next) { next_ = next; }

  const T& get_data(void) const { return data_; }
  void set_data(const T& data) { data_ = data; }

  // E/S
  std::ostream& write(std::ostream& = std::cout) const;

 private:
  T data_;
  sll_node_t<T>* next_;
};


// E/S
template <class T> std::ostream& sll_node_t<T>::write(std::ostream& os) const  {
  os << data_;
  return os;
}

#endif  // SLL_NODET_H_

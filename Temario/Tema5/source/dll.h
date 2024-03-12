// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 4
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef DLLT_H_
#define DLLT_H_

#include <cassert>
#include <iostream>

#include "dll_node.h"

namespace AyED
{

  // Clase para almacenar una lista doblemente enlazada
  template <class T>
  class dll
  {
  public:
    // constructor
    dll(void) : head_(NULL), tail_(NULL), sz_(0) {}

    // destructor
    ~dll(void);

    // getters
    dll_node<T> *get_tail(void) const { return tail_; }
    dll_node<T> *get_head(void) const { return head_; }
    int get_size(void) const { return sz_; }

    bool empty(void) const;

    // operaciones
    void push_back(dll_node<T> *);
    void push_front(dll_node<T> *);

    dll_node<T> *pop_back(void);
    dll_node<T> *pop_front(void);

    dll_node<T> *erase(dll_node<T> *);

    // E/S
    std::ostream &write(std::ostream & = std::cout) const;

  private:
    dll_node<T> *head_;
    dll_node<T> *tail_;
    int sz_;
  };

  // destructor
  template <class T>
  dll<T>::~dll(void)
  {
    while (head_ != NULL)
    {
      dll_node<T> *aux = head_;
      head_ = head_->get_next();
      delete aux;
    }
    sz_ = 0;
    tail_ = NULL;
  }

  // Comprobar si lista vacía
  template <class T>
  bool dll<T>::empty(void) const
  {
    if (head_ == NULL)
    {
      assert(tail_ == NULL);
      assert(sz_ == 0);
      return true;
    }
    else
      return false;
  }

  // operaciones
  template <class T>
  void dll<T>::push_front(dll_node<T> *nodo)
  {
    assert(nodo != NULL);

    if (empty())
    {
      head_ = nodo;
      tail_ = head_;
    }
    else
    {
      head_->set_prev(nodo);
      nodo->set_next(head_);
      head_ = nodo;
    }
    sz_++;
  }

  template <class T>
  void dll<T>::push_back(dll_node<T> *nodo)
  {
    assert(nodo != NULL);

    if (empty())
    {
      head_ = nodo;
      tail_ = head_;
    }
    else
    {
      tail_->set_next(nodo);
      nodo->set_prev(tail_);
      tail_ = nodo;
    }
    sz_++;
  }

  template <class T>
  dll_node<T> *dll<T>::pop_back(void)
  {
    assert(!empty());

    dll_node<T> *aux = tail_;
    tail_ = tail_->get_prev();
    if (tail_ != NULL)
      tail_->set_next(NULL);
    else
      head_ = NULL;
    sz_--;
    aux->set_next(NULL);
    aux->set_prev(NULL);
    return aux;
  }

  template <class T>
  dll_node<T> *dll<T>::pop_front(void)
  {
    assert(!empty());

    dll_node<T> *aux = head_;
    head_ = head_->get_next();
    if (head_ != NULL)
      head_->set_prev(NULL);
    else
      tail_ = NULL;
    sz_--;
    aux->set_next(NULL);
    aux->set_prev(NULL);
    return aux;
  }

  template <class T>
  dll_node<T> *dll<T>::erase(dll_node<T> *nodo)
  {
    assert(nodo != NULL);

    if (nodo->get_prev() != NULL)
      nodo->get_prev()->set_next(nodo->get_next());
    else
      head_ = nodo->get_next();
    if (nodo->get_next() != NULL)
      nodo->get_next()->set_prev(nodo->get_prev());
    else
      tail_ = nodo->get_prev();
    sz_--;
    nodo->set_prev(NULL);
    nodo->set_next(NULL);
    return nodo;
  }

  // E/S
  template <class T>
  std::ostream &dll<T>::write(std::ostream &os) const
  {
    dll_node<T> *aux = head_;

    while (aux != NULL)
    {
      aux->write(os);
      aux = aux->get_next();
    }
    return os;
  }

}

#endif // DLLT_H_

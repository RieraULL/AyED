// AUTOR:
// FECHA:
// EMAIL:
// VERSION: 2.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// TEMA: 2
// ESTILO: Google C++ Style Guide
// COMENTARIOS:

#ifndef VECTORT_H_
#define VECTORT_H_

#include <cassert>
#include <iostream>

namespace AyED
{

  // Clase para vectores
  template <class T>
  class vector
  {
  public:
    // constructores
    vector(const int n = 0) : v_(NULL), sz_(n) { build(); }
    vector(const vector &w) { *this = w; } // constructor de copia

    // operador de asignación
    vector<T> &operator=(const vector<T> &);

    // redimensionado
    void resize(const int);

    // destructor
    ~vector() { destroy(); }

    // getters
    int get_size(void) const { return sz_; }

    // getters-setters
    T &at(const int);
    T &operator[](const int);

    // getters constantes
    const T &at(const int) const;
    const T &operator[](const int) const;

    // E/S
    std::ostream &write(std::ostream & = std::cout) const;
    std::istream &read(std::istream & = std::cin);

  private:
    T *v_;
    int sz_;

  private:
    void build(void);
    void destroy(void);
  };

  // operador de asignación
  template <class T>
  vector<T> &vector<T>::operator=(const vector<T> &w)
  {
    resize(w.get_size());
    for (int i = 0; i < get_size(); ++i)
      at(i) = w.at(i);

    return *this;
  }

  template <class T>
  void vector<T>::build()
  {
    v_ = NULL;
    if (sz_ != 0)
    {
      v_ = new T[sz_];
      assert(v_ != NULL);
    }
  }

  template <class T>
  void vector<T>::destroy()
  {
    if (v_ != NULL)
    {
      delete[] v_;
      v_ = NULL;
    }
    sz_ = 0;
  }

  // redimensionado
  template <class T>
  void vector<T>::resize(const int n)
  {
    destroy();
    sz_ = n;
    build();
  }

  // getters-setters
  template <class T>
  T &vector<T>::at(const int i)
  {
    assert(i >= 0 && i < get_size());
    return v_[i];
  }

  template <class T>
  T &vector<T>::operator[](const int i)
  {
    return at(i);
  }

  // getters constantes
  template <class T>
  const T &vector<T>::at(const int i) const
  {
    assert(i >= 0 && i < get_size());
    return v_[i];
  }

  template <class T>
  const T &vector<T>::operator[](const int i) const
  {
    return at(i);
  }

  // E/S
  template <class T>
  std::ostream &vector<T>::write(std::ostream &os) const
  {
    os << get_size() << ": [ ";
    for (int i = 0; i < get_size(); i++)
      os << at(i) << (i != get_size() - 1 ? "\t" : "");
    os << " ]" << std::endl;
    return os;
  }

  template <class T>
  std::istream &vector<T>::read(std::istream &is)
  {
    is >> sz_;
    resize(sz_);
    for (int i = 0; i < sz_; ++i)
      is >> at(i);
    return is;
  }

  template <class T>
  std::ostream &operator<<(std::ostream &os,
                           const vector<T> &v)
  {
    v.write(os);
    return os;
  }

  template <class T>
  std::istream &operator>>(std::istream &is, vector<T> &v)
  {
    v.read(is);
    return is;
  }
}

#endif // VECTORT_H_

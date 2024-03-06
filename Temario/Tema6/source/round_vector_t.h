// AUTOR: 
// FECHA: 
// EMAIL: 
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// COMENTARIOS: clase que implementa un vector circular

#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;

template <class T>
class round_vector_t{

public:
  // constructor, constructor por defecto y destructor
  round_vector_t(void);
  round_vector_t(const int);
  ~round_vector_t(void);

  // getters
  int get_size(void) const;
  
  // operaciones
  void resize(const int);
  const T& at(const int pos) const;
  T& at(const int pos);
  
  void write(ostream& = cout) const;
  istream& read(istream&);

private:
  T*  v_;  // array que contiene el vector circular
  int sz_; // tamaño del vector circular
  
  void crea_vector(void);
  void destruye_vector(void);
};

template<class T>
round_vector_t<T>::round_vector_t(void):
v_(NULL),
sz_(0)
{}

template<class T>
round_vector_t<T>::round_vector_t(const int sz):
v_(NULL),
sz_(sz)
{
  crea_vector();
}

template<class T>
round_vector_t<T>::~round_vector_t(void)
{
  destruye_vector();
}

template<class T>
int
round_vector_t<T>::get_size(void) const
{
  return sz_;
}

template<class T>
void
round_vector_t<T>::resize(const int sz)
{
  destruye_vector();
  sz_ = sz;
  crea_vector();
}

template<class T>
const T&
round_vector_t<T>::at(const int pos) const
{
  assert(pos >= 0);
  return v_[pos % sz_];
}

template<class T>
T&
round_vector_t<T>::at(const int pos)
{
  assert(pos >= 0);
  return v_[pos % sz_];
}

template<class T>
void
round_vector_t<T>::write(ostream& os) const
{
  os << sz_ << endl;
  for (int i = 0; i < sz_; i++)
  {
    v_[i].write(os);
    os << " ";
  }
}

template<class T>
istream&
round_vector_t<T>::read(istream& is)
{
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> v_[i];
  return is;
}

template<class T>
void
round_vector_t<T>::crea_vector(void)
{
  v_ = new T[sz_];
  assert(v_!= NULL);
}

template<class T>
void
round_vector_t<T>::destruye_vector(void)
{
  if (v_ != NULL)
  {
    delete [] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template<class T>
ostream&
operator<<(ostream& os, const round_vector_t<T>& r)
{
  r.write(os);
  return os;
}

// operador de salida para el tipo double
template<>
ostream&
operator<<(ostream& os, const round_vector_t<double>& r)
{
  os << r.get_size() << endl;
  for (int i = 0; i < r.get_size(); i++)
    os << setw(8) << fixed << setprecision(2) << r.at(i) << " ";
  return os;
}

// operador de salida para el tipo int
template<>
ostream&
operator<<(ostream& os, const round_vector_t<int>& r)
{
  os << r.get_size() << endl;
  for (int i = 0; i < r.get_size(); i++)
    os << r.at(i) << " ";
  return os;
}


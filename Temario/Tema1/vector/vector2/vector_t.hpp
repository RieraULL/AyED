#pragma once

#include <iostream>

using namespace std;

namespace AyED
{

  class vector_t
  {

  public:
    vector_t(void);
    vector_t(size_t sz);
    vector_t(const vector_t &v);
    ~vector_t(void);

    void resize(size_t sz);

    size_t size(void) const;
    double &at(size_t i);
    double at(size_t i) const;

    ostream &write(ostream &os) const;
    istream &read(istream &is);

    double &operator[](size_t i);
    double operator[](size_t i) const;

    size_t ocurrencias(double d, double eps) const;
    double scalprod(const vector_t &v) const;

  private:
    void build(size_t sz);
    void destroy(void);

  private:
    double *base_;
    size_t sz_;
  };

}

ostream &operator<<(ostream &os, const AyED::vector_t &v);
istream &operator>>(istream &is, AyED::vector_t &v);

double operator*(const AyED::vector_t &v, const AyED::vector_t &w);

#pragma once

#include <iostream>


namespace AyED
{

  class vector
  {

  public:
    vector(void);
    vector(size_t sz);
    vector(const vector &v);
    ~vector(void);

    void resize(size_t sz);

    size_t size(void) const;
    double &at(size_t i);
    double at(size_t i) const;

    std::ostream &write(std::ostream &os) const;
    std::istream &read(std::istream &is);

    double &operator[](size_t i);
    double operator[](size_t i) const;

    size_t ocurrencias(double d, double eps) const;
    double scalprod(const vector &v) const;

  private:
    void build(size_t sz);
    void destroy(void);

  private:
    double *base_;
    size_t sz_;
  };

}

std::ostream &operator<<(std::ostream &os, const AyED::vector &v);
std::istream &operator>>(std::istream &is, AyED::vector &v);

double operator*(const AyED::vector &v, const AyED::vector &w);

#include "vector_t.hpp"

#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cassert>

vector_t::vector_t(void):
base_(NULL),
sz_(0)
{}

vector_t::vector_t(size_t sz):
base_(NULL),
sz_(sz)
{
    build(sz_);
}

vector_t::vector_t(const vector_t& v):
base_(NULL),
sz_(v.sz_)
{
    build(sz_);
    
    for(int i = 0; i < sz_; i++)
        base_[i] = v.base_[i];
}

vector_t::~vector_t(void)
{
    destroy();
}

void vector_t::resize(size_t sz)
{
    destroy();
    sz_ = sz;
    build(sz_);
}

size_t vector_t::size(void) const
{
    return sz_;
}

double& vector_t::at(size_t i)
{
	assert(i < sz_);

    return base_[i];
}

double vector_t::at(size_t i) const
{
	assert(i < sz_);

    return base_[i];
}

ostream& vector_t::write(ostream& os) const
{
    os << setw(8) << sz_ << endl;
    
    for(int i = 0; i < sz_; i++)
        os << setw(8) << fixed << setprecision(4) << base_[i] << " ";
        
    os << endl;
}

istream& vector_t::read(istream& is)
{
    is >> sz_;
    
    resize(sz_);
    
    for(int i = 0; i < sz_; i++)
        is >> base_[i];
}

double& vector_t::operator[](size_t i)
{
    return at(i);
}

double vector_t::operator[](size_t i) const
{
    return at(i);
}


void vector_t::build(size_t sz)
{
    base_ = new double [sz];
}

void vector_t::destroy(void)
{
    if (base_ != NULL){
        delete [] base_;
        base_ = NULL;
    }
}

ostream& operator<<(ostream& os, const vector_t& v)
{
    return v.write(os);
}

istream& operator>>(istream& is, vector_t& v)
{
    return v.read(is);
}

size_t vector_t::ocurrencias(double d, double eps) const
{
    size_t cnt = 0;
    
    for(size_t i = 0; i < sz_; i++)
        if (fabs(base_[i] - d) < eps)
            cnt ++;
            
    return cnt;
}

double vector_t::scalprod(const vector_t& v) const
{
    double prod = 0.0;
    
    for(size_t i = 0; i < sz_; i++)
        prod += base_[i] * v.base_[i];
        
    return prod;
}

double operator*(const vector_t& v, const vector_t& w)
{
    return v.scalprod(w);
}


#pragma once

#include <iostream>
#include <cassert>

#define MAX_WIDE 6
#define MAX_PRECISION 2

namespace AyED
{

    template <class T>
    class t_vector
    {
    public:
        t_vector(void);
        t_vector(size_t sz);
        t_vector(const t_vector &v);
        ~t_vector(void);

        size_t size(void) const;

        const T &at(const size_t pos) const;
        T &at(const size_t pos);

        const T &operator[](const size_t pos) const;
        T &operator[](const size_t pos);

        t_vector &operator=(const t_vector &v);

        std::ostream &write(std::ostream &os) const;
        std::istream &read(std::istream &is);

    private:
        void crea_vector_(void);
        void destruye_vector_(void);

    private:
        T *v_;
        size_t sz_;
    };

    template <class T>
    t_vector<T>::t_vector(void) : v_(NULL),
                                  sz_(0) {}

    template <class T>
    t_vector<T>::t_vector(size_t sz) : v_(NULL),
                                       sz_(sz)
    {
        crea_vector_();
    }

    template <class T>
    t_vector<T>::t_vector(const t_vector<T> &v) : v_(NULL),
                                      sz_(v.sz_)
    {
        crea_vector_();

        for (size_t i{0}; i < sz_; i++)
            v_[i] = v.v_[i];
    }

    template <class T>
    t_vector<T> &t_vector<T>::operator=(const t_vector<T> &v)
    {
        if (this != &v)
        {
            destruye_vector_();

            sz_ = v.sz_;
            crea_vector_();

            for (size_t i{0}; i < sz_; i++)
                v_[i] = v.v_[i];
        }

        return *this;
    }

    template <class T>
    t_vector<T>::~t_vector(void)
    {
        destruye_vector_();
    }

    template <class T>
    size_t t_vector<T>::size(void) const
    {
        return sz_;
    }

    template <class T>
    const  T &t_vector<T>::at(const size_t pos) const
    {
        assert(pos < sz_);

        return v_[pos];
    }

    template <class T>
    T &t_vector<T>::at(const size_t pos)
    {
        assert(pos < sz_);

        return v_[pos];
    }

    template <class T>
    const T &t_vector<T>::operator[](const size_t pos) const
    {
        return at(pos);
    }

    template <class T>
    T &t_vector<T>::operator[](const size_t pos)
    {
        return at(pos);
    }

    template <class T>
    std::ostream &t_vector<T>::write(std::ostream &os) const
    {
        os << std::setw(MAX_WIDE) << std::fixed << std::setprecision(0) << sz_ << std::endl;

        for (size_t i{0}; i < sz_; i++)
            os << std::setw(MAX_WIDE) << std::fixed << std::setprecision(MAX_PRECISION) << v_[i] << " ";

        return os;
    }

    template <class T>
    std::istream &t_vector<T>::read(std::istream &is)
    {
        is >> sz_;

        destruye_vector_();
        crea_vector_();

        for (size_t i{0}; i < sz_; i++)
            is >> v_[i];

        return is;
    }

    template <class T>
    void t_vector<T>::crea_vector_(void)
    {
        v_ = new T[sz_];
    }

    template <class T>
    void t_vector<T>::destruye_vector_(void)
    {
        if (v_ != NULL)
        {
            delete[] v_;
            v_ = NULL;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const AyED::t_vector<int> &v)
{
    v.write(os);
    return os;
}

std::istream &operator>>(std::istream &is, AyED::t_vector<int> &v)
{
    return v.read(is);
}

std::ostream &operator<<(std::ostream &os, const AyED::t_vector<double> &v)
{
    v.write(os);
    return os;
}

std::istream &operator>>(std::istream &is, AyED::t_vector<double> &v)
{
    return v.read(is);
}


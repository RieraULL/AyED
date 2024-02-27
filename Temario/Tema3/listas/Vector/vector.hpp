#pragma once

#include <cstdio>
#include <cassert>

namespace AyED
{
    template <class T>
    class vector
    {
    public:
        vector(void);
        vector(int sz);
        vector(const vector &v);
        vector &operator=(const vector &v);
        ~vector(void);

        void resize(int sz);
        int size(void) const;
        const T &at(int pos) const;
        T &at(int pos);

        const T &operator[](int pos) const;
        T &operator[](int pos);

    private:
        void crea_vector(void);
        void destruye_vector(void);

    private:
        T *v_;
        int sz_;
    };
}

namespace AyED
{
    template <class T>
    vector<T>::vector(void) : v_(NULL), sz_(0) {}

    template <class T>
    vector<T>::vector(int sz) : v_(NULL), sz_(sz)
    {
        crea_vector();
    }

    template <class T>
    vector<T>::vector(const vector<T> &v) : v_(NULL), sz_(v.sz_)
    {
        crea_vector();
        for (int i = 0; i < sz_; i++)
            v_[i] = v.v_[i];
    }

    template <class T>
    vector<T> &vector<T>::operator=(const vector<T> &v)
    {
        if (this != &v)
        {
            resize(v.sz_);
            for (int i = 0; i < sz_; i++)
                v_[i] = v.v_[i];
        }
        return *this;
    }

    template <class T>
    vector<T>::~vector(void)
    {
        destruye_vector();
    }

    template <class T>
    void vector<T>::resize(int sz)
    {
        destruye_vector();
        sz_ = sz;
        crea_vector();
    }

    template <class T>
    int vector<T>::size(void) const
    {
        return sz_;
    }

    template <class T>
    const T &vector<T>::at(int pos) const
    {
        assert((pos < sz_) && (pos >= 0));
        return v_[pos];
    }

    template <class T>
    T &vector<T>::at(int pos)
    {
        assert((pos < sz_) && (pos >= 0));
        return v_[pos];
    }

    template <class T>
    const T &vector<T>::operator[](int pos) const
    {
        return at(pos);
    }

    template <class T>
    T &vector<T>::operator[](int pos)
    {
        return at(pos);
    }

    template <class T>
    void vector<T>::crea_vector(void)
    {
        v_ = new T[sz_];
    }

    template <class T>
    void vector<T>::destruye_vector(void)
    {
        if (v_ != NULL)
        {
            delete[] v_;
            v_ = NULL;
        }
    }
}

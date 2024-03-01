#pragma once

#include "vector.hpp"
#include "sll_node.hpp"

#define MAX_SZ 100

#define FREE -2
#define NULL_PTR -1 // Asumiendo que NULL_PTR está definido como -1

namespace AyED
{
    template <class T>
    class memory
    {
    public:
        memory(int max_sz = MAX_SZ);

        int New(const T &data);
        void Delete(int inx);

        sll_node<T> &operator[](int i);
        const sll_node<T> &operator[](int i) const;

    private:
        vector<AyED::sll_node<T>> mem_;
    };
}

// Implementaciones
namespace AyED
{
    template <class T>
    memory<T>::memory(int max_sz) : mem_(max_sz)
    {
        for (int i{0}; i < mem_.size(); i++)
            mem_[i].set_next(FREE);
    }

    template <class T>
    int memory<T>::New(const T &data)
    {
        int i;
        for (i{0}; (i < mem_.size()) && (mem_[i].get_next() != FREE); i++);
        if (i < mem_.size())
        {
            mem_[i].set_data(data);
            mem_[i].set_next(NULL_PTR);
            return i;
        }
        else
            return NULL_PTR;
    }

    template <class T>
    void memory<T>::Delete(int inx)
    {
        mem_[inx].set_next(FREE);
    }

    template <class T>
    sll_node<T> &memory<T>::operator[](int i)
    {
        return mem_[i];
    }

    template <class T>
    const sll_node<T> &memory<T>::operator[](int i) const
    {
        return mem_[i];
    }
}

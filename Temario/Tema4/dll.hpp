#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

#include "dll_node.hpp"

namespace AyED
{

    template <class T>
    class dll_t
    {
    public:
        dll_t(void);
        virtual ~dll_t(void);

        void insert_tail(dll_node_t<T> *);
        void insert_head(dll_node_t<T> *);

        dll_node_t<T> *extract_tail(void);
        dll_node_t<T> *extract_head(void);
        void extract(dll_node_t<T> *);

        dll_node_t<T> *get_tail(void) const;
        dll_node_t<T> *get_head(void) const;

        bool empty(void) const;        

        int get_size(void) const;

        std::ostream &write(std::ostream &os) const;

    private:
        bool is_first(dll_node_t<T> *nodo) const;
        bool is_last(dll_node_t<T> *nodo) const;

    private:
        dll_node_t<T> *head_;
        dll_node_t<T> *tail_;

        int sz_;
    };

    template <class T>
    dll_t<T>::dll_t(void) : head_(NULL),
                            tail_(NULL),
                            sz_(0)
    {
    }

    template <class T>
    dll_t<T>::~dll_t(void)
    {

        dll_node_t<T> *aux = NULL;

        while (head_ != NULL)
        {
            aux = head_;
            head_ = head_->get_next();
            delete aux;
            aux = NULL;
        }
        sz_ = 0;
        head_ = NULL;
        tail_ = NULL;
    }

    template <class T>
    bool dll_t<T>::empty(void) const
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

    template <class T>
    void dll_t<T>::insert_head(dll_node_t<T> *nodo)
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
    void dll_t<T>::insert_tail(dll_node_t<T> *nodo)
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
    dll_node_t<T> *dll_t<T>::extract_tail(void)
    {

        assert(!empty());

        dll_node_t<T> *aux = tail_;

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
    dll_node_t<T> *dll_t<T>::extract_head(void)
    {

        assert(!empty());

        dll_node_t<T> *aux = head_;

        head_ = head_->get_next();

        if (head_)
            head_->set_prev(NULL);
        else
            tail_ = NULL;

        sz_--;

        aux->set_next(NULL);
        aux->set_prev(NULL);

        return aux;
    }

    template <class T>
    dll_node_t<T> *dll_t<T>::get_head(void) const
    {
        return head_;
    }

    template <class T>
    dll_node_t<T> *dll_t<T>::get_tail(void) const
    {
        return tail_;
    }

    template <class T>
    std::ostream &dll_t<T>::write(std::ostream &os) const 
    {

        dll_node_t<T> *aux = head_;

        while (aux != NULL)
        {
            aux->write(os);
            aux = aux->get_next();
        }

        return os;
    }

    template <class T>
    void dll_t<T>::extract(dll_node_t<T> *nodo)
    {

        assert(nodo != NULL);

        if (is_first(nodo))
        {
            extract_head();
        }
        else if (is_last(nodo))
        {
            extract_tail();
        }
        else
        {
            dll_node_t<T> *prev = nodo->get_prev();
            dll_node_t<T> *next = nodo->get_next();

            prev->set_next(next);
            next->set_prev(prev);

            sz_--;
        }
    }

    template <class T>
    int dll_t<T>::get_size(void) const
    {
        return sz_;
    }

    template <class T>
    bool dll_t<T>::is_first(dll_node_t<T> *nodo) const
    {
        return (nodo == head_);
    }

    template <class T>
    bool dll_t<T>::is_last(dll_node_t<T> *nodo) const
    {
        return (nodo == tail_);
    }
}

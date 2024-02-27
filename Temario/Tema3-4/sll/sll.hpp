#pragma once

#include <iostream>
#include <stack>
using namespace std;

#include "sll_node.hpp"

namespace AyED
{

      template <class T>
      class sll
      {
      private:
            sll_node<T> *head_;

      public:
            sll(void);
            virtual ~sll(void);

            void insert_head(sll_node<T> *n);
            sll_node<T> *extract_head(void);

            void insert_after(sll_node<T> *pred, sll_node<T> *n);
            sll_node<T> *extract_after(sll_node<T> *pred);

            sll_node<T> *head(void);

            bool empty(void) const;
            void write(ostream &os) const;
            void inverse_write(ostream &os) const;

            sll_node<T> *tail(void);

            void insert_tail(sll_node<T> *n);

            sll_node<T> *extract_tail(void);

            void invPar(const sll<T> &L)
            {
                  invPar(L.head_);
            }

            void invPar(const sll_node<T> *n)
            {
                  if (n != NULL)
                  {
                        const T &n_d = n->get_data();
                        if (n_d % 2 != 0)
                              insert_head(new sll_node<T>(n_d));

                        invPar(n->get_next());
                  }
            }

            void merge1(sll<T> &L1, sll<T> &L2)
            {
                  sll_node<T> *L1_h = L1.head_;
                  sll_node<T> *L2_h = L2.head_;

                  stack<sll_node<T> *> pila;

                  while ((L1_h != NULL) && (L2_h != NULL))
                  {

                        const T &L1_d = L1_h->get_data();
                        const T &L2_d = L2_h->get_data();

                        if (L1_d < L2_d)
                        {
                              L1_h = L1_h->get_next();
                              sll_node<T> *L1_a = L1.extract_head();
                              pila.push(L1_a);
                        }
                        else
                        {
                              L2_h = L2_h->get_next();
                              sll_node<T> *L2_a = L2.extract_head();
                              pila.push(L2_a);
                        }
                  }

                  while (L1_h != NULL)
                  {
                        L1_h = L1_h->get_next();
                        sll_node<T> *L1_a = L1.extract_head();
                        pila.push(L1_a);
                  }

                  while (L2_h != NULL)
                  {
                        L2_h = L2_h->get_next();
                        sll_node<T> *L2_a = L2.extract_head();
                        pila.push(L2_a);
                  }

                  while (!pila.empty())
                  {
                        sll_node<T> *aux = pila.top();
                        pila.pop();
                        insert_head(aux);
                  }
            }

            void merge2(const sll<T> &L1, const sll<T> &L2)
            {
                  sll_node<T> *L1_h = L1.head_;
                  sll_node<T> *L2_h = L2.head_;

                  while ((L1_h != NULL) && (L2_h != NULL))
                  {

                        const T &L1_d = L1_h->get_data();
                        const T &L2_d = L2_h->get_data();

                        if (L1_d > L2_d)
                        {
                              insert_head(new sll_node<T>(L1_d));
                              L1_h = L1_h->get_next();
                        }
                        else
                        {
                              insert_head(new sll_node<T>(L2_d));
                              L2_h = L2_h->get_next();
                        }
                  }

                  while (L1_h != NULL)
                  {
                        insert_head(new sll_node<T>(L1_h->get_data()));
                        L1_h = L1_h->get_next();
                  }

                  while (L2_h != NULL)
                  {
                        insert_head(new sll_node<T>(L2_h->get_data()));
                        L2_h = L2_h->get_next();
                  }
            }

      private:
            void write_reverse(ostream &os, sll_node<T> *n);
      };

      template <class T>
      sll<T>::sll(void) : head_(NULL) {}

      template <class T>
      sll<T>::~sll(void)
      {

            while (!empty())
            {

                  sll_node<T> *aux = head_;
                  head_ = head_->get_next();
                  delete aux;
            }
      }

      template <class T>
      bool sll<T>::empty(void) const
      {
            return (head_ == NULL);
      }

      template <class T>
      void sll<T>::insert_tail(sll_node<T> *n)
      {
            sll_node<T> *prev = tail();

            if (prev == NULL)
                  insert_head(n);
            else
                  insert_after(prev, n);
      }

      template <class T>
      sll_node<T> *sll<T>::tail(void)
      {
            if (empty())
                  return NULL;
            else
            {

                  sll_node<T> *aux = head_;

                  while (aux->get_next() != NULL)
                        aux = aux->get_next();

                  return aux;
            }
      }

      template <class T>
      sll_node<T> *sll<T>::extract_tail(void)
      {
            assert(!empty());

            if (head_->get_next() == NULL)
                  return extract_head();

            else
            {
                  sll_node<T> *aux = head_;

                  while (aux->get_next()->get_next() != NULL)
                        aux = aux->get_next();

                  return extract_after(aux);
            }
      }

      template <class T>
      void sll<T>::insert_head(sll_node<T> *n)
      {
            n->set_next(head_);
            head_ = n;
      }

      template <class T>
      sll_node<T> *sll<T>::extract_head(void)
      {

            sll_node<T> *aux = head_;
            head_ = head_->get_next();
            aux->set_next(NULL);

            return aux;
      }

      template <class T>
      void sll<T>::insert_after(sll_node<T> *prev, sll_node<T> *n)
      {
            n->set_next(prev->get_next());
            prev->set_next(n);
      }

      template <class T>
      sll_node<T> *sll<T>::head(void)
      {
            return head_;
      }

      template <class T>
      sll_node<T> *sll<T>::extract_after(sll_node<T> *prev)
      {
            sll_node<T> *aux = prev->get_next();
            prev->set_next(aux->get_next());
            aux->set_next(NULL);

            return aux;
      }

      template <class T>
      void sll<T>::write(ostream &os) const
      {
            sll_node<T> *aux = head_;

            while (aux != NULL)
            {
                  aux->write(os);
                  aux = aux->get_next();
            }
      }

      template <class T>
      void sll<T>::inverse_write(ostream &os) const
      {
            write_reverse(head_);
      }

      template <class T>
      void sll<T>::write_reverse(ostream &os, sll_node<T> *n)
      {
            if (n != NULL)
                  write_reverse(os, n->get_next());
            else
                  os << n->get_data() << " ";
      }

}

#pragma once

#include <iostream>

#include "sll_node.hpp"

namespace AyED
{

	template <class T>
	class sll
	{

	public:
		sll(void);
		virtual ~sll(void);

		void insert_head(sll_node<T> *n);
		sll_node<T> *extract_head(void);

		void insert_after(sll_node<T> *pred, sll_node<T> *n);
		sll_node<T> *extract_after(sll_node<T> *pred);

		bool empty(void) const;
		std::ostream &write(std::ostream &os) const;

		sll_node<T> *search(const T &d) const;

	private:
		sll_node<T> *head_;
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
	sll_node<T> *sll<T>::extract_after(sll_node<T> *prev)
	{

		sll_node<T> *aux = prev->get_next();
		prev->set_next(aux->get_next());
		aux->set_next(NULL);

		return aux;
	}

	template <class T>
	std::ostream &sll<T>::write(std::ostream &os) const
	{

		sll_node<T> *aux = head_;

		while (aux != NULL)
		{
			aux->write(os);
			aux = aux->get_next();
		}

		return os;
	}

	template <class T>
	sll_node<T> *sll<T>::search(const T &d) const
	{
		sll_node<T> *aux = head_;

		while ((aux != NULL) && (aux->get_data() != d))
			aux = aux->get_next();

		return aux;
	}

}

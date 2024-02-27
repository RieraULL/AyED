#pragma once

#include <iostream>
using namespace std;

#include "sll_node.hpp"
#include "memory.hpp"

namespace AyED
{

	template <class T>
	class sll
	{
	public:
		sll(memory<T> &memory);
		virtual ~sll(void);

		void insert_head(int n);
		int extract_head(void);

		void insert_after(int pred, int n);
		int extract_after(int pred);

		bool empty(void) const;
		ostream &write(ostream &os) const;

		int search(const T &d) const;

	private:
		int head_;
		memory<T> &memory_;
	};

	template <class T>
	sll<T>::sll(memory<T> &memory) : head_(NULL_PTR),
									   memory_(memory) {}

	template <class T>
	sll<T>::~sll(void) {}

	template <class T>
	bool sll<T>::empty(void) const
	{
		return (head_ == NULL_PTR);
	}

	template <class T>
	void sll<T>::insert_head(int n)
	{
		memory_[n].set_next(head_);
		head_ = n;
	}

	template <class T>
	int sll<T>::extract_head(void)
	{

		int aux = head_;
		head_ = memory_[head_].get_next();
		memory_[aux].set_next(NULL_PTR);

		return aux;
	}

	template <class T>
	void sll<T>::insert_after(int prev, int n)
	{
		memory_[n].set_next(memory_[prev].get_next());
		memory_[prev].set_next(n);
	}

	template <class T>
	int sll<T>::extract_after(int prev)
	{

		int aux = memory_[prev].get_next();
		memory_[prev].set_next(memory_[aux].get_next());
		memory_[aux].set_next(NULL_PTR);

		return aux;
	}

	template <class T>
	ostream &sll<T>::write(ostream &os) const
	{

		int aux = head_;

		while (aux != NULL_PTR)
		{
			memory_[aux].write(os);
			aux = memory_[aux].get_next();
		}

		return os;
	}

	template <class T>
	int sll<T>::search(const T &d) const
	{
		int aux = head_;

		while ((aux != NULL_PTR) && (memory_[aux].get_data() != d))
			aux = memory_[aux].get_next();

		return aux;
	}

}

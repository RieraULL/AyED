#pragma once

#include <iostream>
using namespace std;

namespace AyED
{

	template <class T>
	class sll_node
	{
	private:
		T data_;
		sll_node<T> *next_;

	public:
		sll_node(void);
		sll_node(T data);
		~sll_node(void);

		void set_next(sll_node<T> *next);
		sll_node<T> *get_next(void) const;

		const T &get_data(void) const;

		ostream &write(ostream &os) const;
	};

	template <class T>
	sll_node<T>::sll_node() : data_(),
							  next_(NULL)
	{
	}

	template <class T>
	sll_node<T>::sll_node(T data) : data_(data),
									next_(NULL)
	{
	}

	template <class T>
	sll_node<T>::~sll_node(void)
	{
		next_ = NULL;
	}

	template <class T>
	void sll_node<T>::set_next(sll_node<T> *next)
	{
		next_ = next;
	}

	template <class T>
	sll_node<T> *sll_node<T>::get_next(void) const
	{
		return next_;
	}

	template <class T>
	const T &sll_node<T>::get_data(void) const
	{
		return data_;
	}

	template <class T>
	ostream &sll_node<T>::write(ostream &os) const
	{
		os << data_;
		return os;
	}
}

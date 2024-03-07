#pragma once

#include <cassert>
#include <iostream>
#include <cstdio>

namespace AyED
{

	template <class T>
	class dll_node
	{

	public:
		dll_node();
		dll_node(const T &data);

		virtual ~dll_node(void);

		void set_next(dll_node<T> *);
		void set_prev(dll_node<T> *);

		dll_node<T> *get_next(void) const;
		dll_node<T> *get_prev(void) const;

		void set_data(const T &data);
		T get_data(void) const;

		std::ostream &write(std::ostream &os) const;

	private:
		dll_node<T> *next_;
		dll_node<T> *prev_;

		T data_;
	};

	template <class T>
	dll_node<T>::dll_node() : next_(NULL),
								  prev_(NULL),
								  data_()
	{
	}

	template <class T>
	dll_node<T>::dll_node(const T &data) : next_(NULL),
											   prev_(NULL),
											   data_(data)
	{
	}

	template <class T>
	dll_node<T>::~dll_node(void)
	{
		prev_ = NULL;
		next_ = NULL;
	}

	template <class T>
	void dll_node<T>::set_next(dll_node<T> *next)
	{
		next_ = next;
	}

	template <class T>
	dll_node<T> *dll_node<T>::get_next(void) const
	{
		return next_;
	}

	template <class T>
	void dll_node<T>::set_prev(dll_node<T> *prev)
	{
		prev_ = prev;
	}

	template <class T>
	dll_node<T> *dll_node<T>::get_prev(void) const
	{
		return prev_;
	}

	template <class T>
	void dll_node<T>::set_data(const T &data)
	{
		data_ = data;
	}

	template <class T>
	T dll_node<T>::get_data(void) const
	{
		return data_;
	}

	template <class T>
	std::ostream &dll_node<T>::write(std::ostream &os) const
	{
		os << data_;
		return os;
	}

}

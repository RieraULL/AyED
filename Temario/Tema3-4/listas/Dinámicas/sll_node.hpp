#pragma once

#include <iostream>

namespace AyED
{

	template <class T>
	class sll_node
	{

	public:
		sll_node(void);
		sll_node(const T &data);
		~sll_node(void);

		void set_next(sll_node<T> *next);
		sll_node<T> *get_next(void) const;

		void set_data(const T &data);
		const T &get_data(void) const;

		std::ostream &write(std::ostream &os) const;

	private:
		T data_;
		sll_node<T> *next_;
	};

	template <class T>
	sll_node<T>::sll_node() : data_(),
							  next_(NULL)
	{
	}

	template <class T>
	sll_node<T>::sll_node(const T &data) : data_(data),
										   next_(NULL)
	{
	}

	template <class T>
	sll_node<T>::~sll_node(void)
	{
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
	void sll_node<T>::set_data(const T &data)
	{
		data_ = data;
	}

	template <class T>
	const T &sll_node<T>::get_data(void) const
	{
		return data_;
	}

	template <class T>
	std::ostream &sll_node<T>::write(std::ostream &os) const
	{
		os << data_;
		return os;
	}
}

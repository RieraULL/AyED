#pragma once

#include <exception>

namespace AyED
{

	class stack_exception : public std::exception
	{
	};

	class empty_stack_exception : public stack_exception
	{
	public:
		virtual const char *what(void) const throw()
		{
			return "Empty stack";
		}
	};

	class stack_overflow_exception : public stack_exception
	{
	public:
		virtual const char *what(void) const throw()
		{
			return "Stack overflow";
		}
	};

	template <class T>
	class stack
	{

	public:
		stack(void) {}

		virtual ~stack(void) {}

		void push(T dato)
		{
			if (full())
				throw stack_overflow_exception();
			else
				_push(dato);
		}

		void pop(void)
		{
			if (empty())
				throw empty_stack_exception();
			else
				_pop();
		}

		T top(void) const
		{
			if (empty())
				throw empty_stack_exception();
			else
				return _top();
		}

		virtual bool empty(void) const = 0;

		virtual void _push(T dato) = 0;
		virtual void _pop(void) = 0;
		virtual T _top(void) const = 0;

	protected:
		virtual bool full(void) const = 0;
	};

}

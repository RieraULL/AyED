#pragma once

#include "stack.hpp"
#include <vector>
#include <iomanip>

#define MAX_STACK_SIZE 20

using namespace std;

namespace AyED
{

	template <class T>
	class stack_v : public stack<T>
	{
	private:
		std::vector<T> v_;
		int top_;

	public:
		stack_v(void) : stack<T>(),
						v_(MAX_STACK_SIZE),
						top_(-1) {}

		virtual ~stack_v(void) {}

		virtual bool empty(void) const
		{
			return (top_ < 0);
		}

		virtual T _top(void) const
		{
			return v_[top_];
		}

		virtual void _pop(void)
		{

			top_--;
		}

		virtual void _push(T dato)
		{

			top_++;
			v_[top_] = dato;
		}

	protected:
		virtual bool full(void) const
		{
			return (top_ >= MAX_STACK_SIZE - 1);
		}
	};
}

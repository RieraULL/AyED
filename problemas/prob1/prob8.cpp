#include <iostream>
#include <cassert>

namespace AyED
{

	template <class T>
	class sll_node_t
	{
	public:
		sll_node_t(void);
		sll_node_t(T data);
		~sll_node_t(void);

		void set_next(sll_node_t<T> *next);
		sll_node_t<T> *get_next(void) const;

		void set_data(const T &data);
		const T &get_data(void) const;

		std::ostream &write(std::ostream &os) const;

	private:
		T data_;
		sll_node_t<T> *next_;
	};

	template <class T>
	sll_node_t<T>::sll_node_t() : data_(),
								  next_(NULL)
	{
	}

	template <class T>
	sll_node_t<T>::sll_node_t(T data) : data_(data),
										next_(NULL)
	{
	}

	template <class T>
	sll_node_t<T>::~sll_node_t(void)
	{
		next_ = NULL;
	}

	template <class T>
	void sll_node_t<T>::set_next(sll_node_t<T> *next)
	{
		next_ = next;
	}

	template <class T>
	sll_node_t<T> *sll_node_t<T>::get_next(void) const
	{
		return next_;
	}

	template <class T>
	void sll_node_t<T>::set_data(const T &data)
	{
		data_ = data;
	}

	template <class T>
	const T &sll_node_t<T>::get_data(void) const
	{
		return data_;
	}

	template <class T>
	std::ostream &sll_node_t<T>::write(std::ostream &os) const
	{
		return os << data_ << " ";
	}

	template <class T>
	class sll_q_t
	{
	public:
		sll_q_t(void) : head_(NULL), tail_(NULL) {}
		~sll_q_t(void)
		{
			while (!empty())
			{
				sll_node_t<T> *aux = head_;
				head_ = head_->get_next();
				delete aux;
			}
		}

		bool empty(void) const { return head_ == NULL; }
		sll_node_t<T> *head(void) const { return head_; }
		sll_node_t<T> *tail(void) const { return tail_; }

		void insert_tail(sll_node_t<T> *n)
		{
			if (tail_ == NULL)
				head_ = n;
			else
				tail_->set_next(n);

			tail_ = n;
		}

		sll_node_t<T> *extract_head(void)
		{
			assert(!empty());
			sll_node_t<T> *n = head_;
			head_ = head_->get_next();
			if (empty())
				tail_ = NULL;
			return n;
		}

		std::ostream &write(std::ostream &os) const
		{
			sll_node_t<T> *aux = head_;
			while (aux != NULL)
			{
				aux->write(os);
				aux = aux->get_next();
			}
			os << std::endl;
			return os;
		}

	private:
		sll_node_t<T> *head_;
		sll_node_t<T> *tail_;
	};

	template <class T>
	class queue_sll_q_t
	{

	public:
		queue_sll_q_t(void) : queue_() {}
		~queue_sll_q_t(void) {}

		bool empty(void) const { return queue_.empty(); }

		void push(const T &d)
		{
			sll_node_t<T> *n = new sll_node_t<T>(d);
			queue_.insert_tail(n);
		}

		void pop(void)
		{
			delete queue_.extract_head();
		}

		const T &front() { return queue_.head()->get_data(); }
		const T &back() { return queue_.tail()->get_data(); }

		std::ostream &write(std::ostream &os = std::cout) { return queue_.write(os); }

	private:
		sll_q_t<T> queue_;
	};

}

int main()
{
	AyED::queue_sll_q_t<int> Q;

	for (int i = 1; i <= 7; i++)
	{
		Q.push(i);
		std::cout << "Cola: ";
		Q.write();
	}

	std::cout << "front: " << Q.front() << std::endl;
	std::cout << "back: " << Q.back() << std::endl;

	while (!Q.empty())
	{
		std::cout << "Cola: ";
		Q.write();
		Q.pop();
	}

	return 0;
}

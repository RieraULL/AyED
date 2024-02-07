#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

namespace AyED
{

	class position
	{

	public:
		position(int x, int y) : x_(x),
								   y_(y) {}

		~position(void) {}

		void set(int x, int y)
		{
			x_ = x;
			y_ = y;
		}

		int get_x(void) { return x_; }
		int get_t(void) { return y_; }

		void write(std::ostream &os) { os << "(" << x_ << ", " << y_ << ")"; }

	private:
		int x_;
		int y_;
	};

	class shape : public position
	{

	public:
		shape(const position &p) : position(p) {}

		virtual ~shape(void) {}

		virtual double area(void) = 0;
		virtual double perimeter(void) = 0;
		virtual void write(std::ostream &os) = 0;
	};

	class trapecio : public shape
	{
	public:
		trapecio(const position &p, double base, double Base, double h) : shape(p),
																			  base_(base),
																			  Base_(Base),
																			  h_(h) {}

		virtual ~trapecio(void) {}

		virtual double area(void) { return (Base_ + base_) * h_ * 0.5; }

		virtual double perimeter(void) { Base_ + base_ + 2 * sqrt(h_ * h_ + (Base_ - base_) * (Base_ - base_) * 0.25); }

		virtual void write(std::ostream &os)
		{
			os << "Trapecio en posición: ";
			position::write(os);
		}

	private:
		double base_;
		double Base_;
		double h_;
	};

	class triangle : public trapecio
	{
	public:
		triangle(const position &p, double Base, double h) : trapecio(p, 0, Base, h) {}

		virtual ~triangle(void) {}

		virtual void write(std::ostream &os)
		{
			os << "Triángulo en posición: ";
			position::write(os);
		}
	};

	class rectangle : public trapecio
	{
	public:
		rectangle(const position &p, double Base, double h) : trapecio(p, Base, Base, h) {}

		virtual ~rectangle(void) {}

		virtual void write(std::ostream &os)
		{
			os << "Rectángulo en posición: ";
			position::write(os);
		}
	};

	class square : public rectangle
	{
	public:
		square(const position &p, double base) : rectangle(p, base, base) {}

		virtual ~square(void){};

		virtual void write(std::ostream &os)
		{
			os << "Cuadrado en posición: ";
			position::write(os);
		}
	};
}

int main(void)
{
	std::vector<AyED::shape *> formas(4);

	formas[0] = new AyED::square(AyED::position(1, 1), 5);
	formas[1] = new AyED::rectangle(AyED::position(3, 2), 4, 3);
	formas[2] = new AyED::triangle(AyED::position(4, 6), 2, 1);
	formas[3] = new AyED::trapecio(AyED::position(1, 1), 5, 4, 3);

	for (int i = 0; i < 4; i++)
	{
		formas[i]->write(std::cout);
		std::cout << std::endl;
		std::cout << "Area     : " << formas[i]->area() << std::endl;
		std::cout << "Perímetro: " << formas[i]->perimeter() << std::endl;
	}

	return 0;
}

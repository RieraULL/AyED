/* Compilación: g++ -g code5.cpp -o code5 */

#include <cmath>
#include <iostream>
#include <iomanip>

namespace AyED
{

	class complex
	{
	private:
		double r_;
		double i_;

	public:
		complex(double r, double i);
		complex(void);

		~complex(void);

		void write_cartesian(std::ostream &os) const;
		void write_polar(std::ostream &os) const;

		void set_real(double r);
		void set_imag(double i);

		double get_real(void) const;
		double get_imag(void) const;

		void get(complex &c) const;
		void set(const complex &c);

	private:
		double get_mod(void) const;
		double get_phase(void) const;
	};

	complex::complex(double r, double i): r_(r), i_(i)
	{}

	complex::complex(void): r_(0), i_(0)
	{}

	complex::~complex(void)
	{
		std::cout << "-- Bye, bye, complex! --" << std::endl;
	}

	void complex::write_cartesian(std::ostream &os) const
	{
		os << std::setw(3) << std::fixed << std::setprecision(1) << r_;
		os << " + ";
		os << std::setw(3) << std::fixed << std::setprecision(1) << i_;
		os << "i";
	}

	void complex::write_polar(std::ostream &os) const
	{
		const double mod = get_mod();
		const double pha = get_phase();

		os << std::setw(3) << std::fixed << std::setprecision(1) << mod;
		os << " cos(";
		os << std::setw(3) << std::fixed << std::setprecision(1) << pha;
		os << ") + ";
		os << std::setw(3) << std::fixed << std::setprecision(1) << mod;
		os << " i sin(";
		os << std::setw(3) << std::fixed << std::setprecision(1) << pha;
		os << ")";
	}

	void complex::get(complex &c) const
	{
		c.r_ = r_;
		c.i_ = i_;
	}

	void complex::set(const complex &c)
	{
		r_ = c.r_;
		i_ = c.i_;
	}

	void complex::set_real(double r)
	{
		r_ = r;
	}

	void complex::set_imag(double i)
	{
		i_ = i;
	}

	double complex::get_real(void) const
	{
		return r_;
	}

	double complex::get_imag(void) const
	{
		return i_;
	}

	double complex::get_mod(void) const
	{
		return sqrt(r_ * r_ + i_ * i_);
	}

	double complex::get_phase(void) const
	{
		return atan2(i_, r_);
	}

}

int main(void)
{
	AyED::complex a(1, 2), b, c;

	b.set(a);
	b.get(c);

	b.write_cartesian(std::cout);
	std::cout << std::endl;
	c.write_cartesian(std::cout);
	std::cout << std::endl;

	return 0;
}

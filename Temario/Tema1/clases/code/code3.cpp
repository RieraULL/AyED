/* Compilación: g++ -g code3.cpp -o code3 */

#include <cmath>
#include <iostream>
#include <iomanip>

namespace AyED
{

	class complex
	{

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

	private:
		double r_;
		double i_;
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
	AyED::complex a(1, 2), b(3, 4);

	AyED::complex *ap, *bp, *cp, *dp;

	ap = &a;
	bp = new AyED::complex(6, 7);
	cp = new AyED::complex(b);
	dp = NULL;

	std::cout << std::endl;
	ap->write_cartesian(std::cout);
	std::cout << std::endl;
	bp->write_cartesian(std::cout);
	std::cout << std::endl;
	cp->write_cartesian(std::cout);
	std::cout << std::endl;
	/* dp->write_cartesian(std::cout);  ERROR */
	std::cout << std::endl;

	ap = NULL;

	delete bp;
	bp = NULL;

	delete cp;
	cp = NULL;

	return 0;
}

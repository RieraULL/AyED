/* Compilación: g++ -g code3.cpp -o code3 */

#include <cmath>
#include <iostream>
#include <iomanip>

namespace AyED
{

	class complex_t
	{

	public:
		complex_t(double r, double i);
		complex_t(void);

		~complex_t(void);

		void write_cartesian(std::ostream &os) const;
		void write_polar(std::ostream &os) const;

		void set_real(double r);
		void set_imag(double i);

		double get_real(void) const;
		double get_imag(void) const;

		void get(complex_t &c) const;
		void set(const complex_t &c);

	private:
		double get_mod(void) const;
		double get_phase(void) const;

	private:
		double r_;
		double i_;
	};

	complex_t::complex_t(double r, double i)
	{
		r_ = r;
		i_ = i;
	}

	complex_t::complex_t(void)
	{
		r_ = 0;
		i_ = 0;
	}

	complex_t::~complex_t(void)
	{
		std::cout << "-- Bye, bye, complex! --" << std::endl;
	}

	void complex_t::write_cartesian(std::ostream &os) const
	{
		os << std::setw(3) << std::fixed << std::setprecision(1) << r_;
		os << " + ";
		os << std::setw(3) << std::fixed << std::setprecision(1) << i_;
		os << "i";
	}

	void complex_t::write_polar(std::ostream &os) const
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

	void complex_t::get(complex_t &c) const
	{
		c.r_ = r_;
		c.i_ = i_;
	}

	void complex_t::set(const complex_t &c)
	{
		r_ = c.r_;
		i_ = c.i_;
	}

	void complex_t::set_real(double r)
	{
		r_ = r;
	}

	void complex_t::set_imag(double i)
	{
		i_ = i;
	}

	double complex_t::get_real(void) const
	{
		return r_;
	}

	double complex_t::get_imag(void) const
	{
		return i_;
	}

	double complex_t::get_mod(void) const
	{
		return sqrt(r_ * r_ + i_ * i_);
	}

	double complex_t::get_phase(void) const
	{
		return atan2(i_, r_);
	}

}

int main(void)
{
	AyED::complex_t a(1, 2), b(3, 4);

	AyED::complex_t *ap, *bp, *cp, *dp;

	ap = &a;
	bp = new AyED::complex_t(6, 7);
	cp = new AyED::complex_t(b);
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

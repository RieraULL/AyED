#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

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

	std::ostream &operator<<(std::ostream &os, const complex &c)
	{
		c.write_cartesian(os);
		return os;
	}

	complex operator+(const complex &c1, const complex &c2)
	{
		complex aux;

		aux.set_real(c1.get_real() + c2.get_real());
		aux.set_imag(c1.get_imag() + c2.get_imag());

		return aux;
	}

	complex operator*(const complex &c1, const complex &c2)
	{
		complex aux;

		aux.set_real(c1.get_real() * c2.get_real() - c1.get_imag() * c2.get_imag());
		aux.set_imag(c1.get_real() * c2.get_imag() + c2.get_real() * c1.get_imag());

		return aux;
	}

	bool operator==(const complex &c1, const complex &c2)
	{
		return (c1.get_real() == c2.get_real()) && (c1.get_imag() == c2.get_imag());
	}
}

int main(void)
{
	AyED::complex a(1, 2), b(2, 3), c(3, 4), d;

	std::cout << std::endl;
	a.write_cartesian(std::cout);
	std::cout << std::endl;
	b.write_cartesian(std::cout);
	std::cout << std::endl;
	c.write_cartesian(std::cout);
	std::cout << std::endl;
	d.write_cartesian(std::cout);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	a.write_polar(std::cout);
	std::cout << std::endl;
	b.write_polar(std::cout);
	std::cout << std::endl;
	c.write_polar(std::cout);
	std::cout << std::endl;
	d.write_polar(std::cout);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << std::endl;

	std::cout << "Parte real      : " << a.get_real() << std::endl;
	std::cout << "Parte imaginaria: " << a.get_imag() << std::endl;

	std::cout << std::endl;

	const AyED::complex aa(a), bb = b, cc(c), dd(d);

	std::cout << std::endl;
	aa.write_cartesian(std::cout);
	std::cout << std::endl;
	bb.write_cartesian(std::cout);
	std::cout << std::endl;
	cc.write_cartesian(std::cout);
	std::cout << std::endl;
	dd.write_cartesian(std::cout);
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Parte real      : " << aa.get_real() << std::endl;
	std::cout << "Parte imaginaria: " << aa.get_imag() << std::endl;

	std::cout << std::endl;

	AyED::complex * ap, *bp, *cp, *dp;

	ap = &a;
	bp = new AyED::complex(6, 7);
	cp = new AyED::complex(bb);
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

	AyED::complex &ar(a), &br = a;
	const AyED::complex &cr = a;

	std::cout << std::endl;
	ar.write_cartesian(std::cout);
	std::cout << std::endl;

	ar.set_real(25);

	ar.write_cartesian(std::cout);
	std::cout << std::endl;

	br.set_real(2);
	a.write_cartesian(std::cout);
	std::cout << std::endl;

	cr.write_cartesian(std::cout);
	std::cout << std::endl;

	/* cr.set_real(5);  ERROR */

	std::cout << "Cambiando número: " << a;
	a.set(c);
	// a.r_=5;               // ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!
	std::cout << " a " << a << std::endl;
	std::cout << std::endl;

	std::cout << "Suma            : " << a << " + " << b << " = ";

	c = a + b;

	std::cout << c << std::endl;
	std::cout << std::endl;

	std::cout << "Producto        : " << a << " * " << b << " = ";

	d = a * b;

	std::cout << d << std::endl;
	std::cout << std::endl;

	return 0;
}

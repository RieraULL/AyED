/* Compilación: g++ -g code2.cpp -o code2 */

#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;


class complex_t {

private:

	double r_;
	double i_;

public:

	complex_t(double r,double i);
	complex_t(void);

	~complex_t(void);
	
	void write_cartesian(ostream& os) const;
	void write_polar(ostream& os) const;

	void set_real(double r);
	void set_imag(double i);
	
	double get_real(void) const;
	double get_imag(void) const;

	void get(complex_t& c) const;
	void set(const complex_t& c);

private:

	double get_mod(void) const;
	double get_phase(void) const;
};
 
complex_t::complex_t(double r,double i)
{
	r_=r;
	i_=i;
}

complex_t::complex_t(void)
{
	r_=0;
	i_=0;
}

complex_t::~complex_t(void)
{
	cout << "-- Bye, bye, complex! --" << endl;
}

void complex_t::write_cartesian(ostream& os) const
{
	os << setw(3) << fixed << setprecision(1) << r_;
	os << " + ";
	os << setw(3) << fixed << setprecision(1) << i_;
	os << "i";
}

void complex_t::write_polar(ostream& os) const
{
	const double mod = get_mod();
	const double pha = get_phase();

	os << setw(3) << fixed << setprecision(1) << mod;
	os << " cos(";
	os << setw(3) << fixed << setprecision(1) << pha;
	os << ") + ";
	os << setw(3) << fixed << setprecision(1) << mod;
	os << " i sin(";
	os << setw(3) << fixed << setprecision(1) << pha;
	os << ")";
}

void complex_t::get(complex_t& c) const
{
	c.r_ = r_;
	c.i_ = i_;
}

void complex_t::set(const complex_t& c)
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
	return sqrt(r_ * r_ + i_* i_);	
}

double complex_t::get_phase(void) const
{
	return atan2(i_, r_);	
}

int main(void)
{
	complex_t a(1, 2), b;

	const complex_t aa(a), bb = b;

	cout << endl;
	aa.write_cartesian(cout); cout << endl;
	bb.write_cartesian(cout); cout << endl;
	cout << endl;

	cout << "Parte real      : "<< aa.get_real()<< endl;
	cout << "Parte imaginaria: "<< aa.get_imag()<< endl;

	// bb.set_real(1.0); ERROR

	cout << endl;

}


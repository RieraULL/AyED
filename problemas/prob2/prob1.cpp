#include <iostream>

#include "point_t.hpp"
#include "line_eq_t.hpp"

int main(void)
{
	AyED::point_t p1(3, 4);
	AyED::point_t p2(4, 3);

	AyED::line_equ_t l1(1, -1);

	std::cout << "Distancia entre la recta ";
	l1.write(std::cout);
	std::cout << " y el punto ";
	p1.write(std::cout);
	std::cout << " es ";
	std::cout << l1.distance(p1) << endl;

	std::cout << "Distancia entre la recta ";
	l1.write(std::cout);
	std::cout << " y el punto ";
	p2.write(std::cout);
	std::cout << " es ";
	std::cout << l1.distance(p2) << std::endl;

	return 0;
}

#include <cstdio>
#include <iostream>

#include "template_matrix.hpp"

int main(void)
{
  	AyED::matrix<double> A(10,10);

	for(int i = 1; i <= A.get_m(); i++)
		for(int j = 1; j <= A.get_n(); j++)
			A.at(i,j) = 1.233 + i * 0.3;

	A.write(std::cout);
	std::cout << std::endl;

  	AyED::matrix<int> B(10,10);

	for(int i = 1; i <= B.get_m(); i++)
		for(int j = 1; j <= B.get_n(); j++)
			B.at(i,j) = i * B.get_n() + j;

	B.write(std::cout);
	std::cout << std::endl;

  	AyED::matrix<char> C(10,10);

	for(int i = 1; i <= C.get_m(); i++)
		for(int j = 1; j <= C.get_n(); j++)
			C.at(i,j) = 'A' + i + j;

	C.write(std::cout);
	std::cout << std::endl;

}


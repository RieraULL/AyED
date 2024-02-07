#include <cstdio>
#include <iostream>

#include "template_vector.hpp"

using namespace std;

int main(void)
{


  	AyED::vector<double> v(10);

	for(int i = 0; i < v.size(); i++)
		v.at(i) = 34.3346 + i * 0.5;

	v.write(cout);
	cout << endl;

  	AyED::vector<int> w(10);

	for(int i = 0; i < v.size(); i++)
		w.at(i) = i;

	w.write(cout);
	cout << endl;	

	return 0;
}

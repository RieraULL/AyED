
/* Compilar: g++ -g pointer1.cpp -o pointer1CPP   */                                                         

#include <cstdio>
#include <iostream>
#include <iomanip>

int main(void){
	
 	int    a;
 	double b; 
 
 	int    *a_ptr = NULL; 
 	double *b_ptr = NULL;
 		
 	a = 5;
	b = 12.6; 
	
	a_ptr = &a; 
	b_ptr = &b; 
	
	std::cout << std::setw(4) << a << std::setw(16) <<  a_ptr << std::endl; 
	std::cout << std::setw(4) << std::fixed << std::setprecision(1) << b << std::setw(16) <<  b_ptr << std::endl; 
	std::cout << std::setw(4) << a << std::setw(16) << *a_ptr << std::endl; 

	return 0;
}

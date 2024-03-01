
/* Compilar: g++ -g pointer2.cpp -o pointer2CPP   */                                                         

#include <cstdio>
#include <iostream>
#include <iomanip>


#define MAXIMO 10

int main(void){
	
	int    a[MAXIMO];
 	double b[MAXIMO]; 
 	
	int    *a_ptr = NULL; 
 	double *b_ptr = NULL;
 	
 	a_ptr = a;
 	b_ptr = b;
	
	for(int i{0}; i < MAXIMO; i++)
	{			
		a[i] = i;
		b[i] = i + 0.5;
	}

	for(int i{0}; i < MAXIMO; i++)
	{	
		std::cout << std::setw(4) << a[i] << std::setw(4) << *(a_ptr + i) << std::endl; 
		std::cout << std::setw(4) << a_ptr[i] << std::setw(4) << *(a + i) << std::endl; 
	}

	return 0;
}

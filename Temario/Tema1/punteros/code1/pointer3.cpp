
/* Compilar: g++ -g pointer3.cpp -o pointer3CPP   */                                                         

#include <cstdio>
#include <iostream>
#include <iomanip>

#define MAXIMO 10

int main(void){
	
	int a[MAXIMO];
 	
	int *a_ptr = NULL; 

	for(int i = 0; i < MAXIMO; i++)
	{			
		a[i] = i;
	}
			
	a_ptr = a;

	for(int i = 0; i < MAXIMO; i++)
	{			
		std::cout << std::setw(4) << a[i] << std::setw(4) << *a_ptr << std::endl;
		a_ptr ++;
	}

	return 0;
}

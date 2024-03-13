#include <iostream>
#include "stack_v.hpp"

int main(void)
{
	
	AyED::stack_v<char> pila_vector;



	for(int i{0}; i < MAX_STACK_SIZE + 1; i++){

		try {
			pila_vector.push('a' + i);
		 }
		catch(AyED::stack_exception& e)
  		{
    			std::cout << "Excepción de la clase 'stack_t': ";
   			std::cout << e.what() <<  std::endl;
  		}
 		catch(exception& e)
  		{
		    	std::cout << e.what() <<  std::endl;
  		}
	}

	while(!pila_vector.empty()){
		
		try{
			pila_vector.pop();
		}
		catch(AyED::stack_exception& e)
  		{
    			std::cout << "Excepción de la clase 'stack_t': ";
   			std::cout << e.what() <<  std::endl;
  		}
 		catch(exception& e)
  		{
		    	std::cout << e.what() <<  std::endl;
  		}
	}
	

	try{
		pila_vector.pop();
	}
	catch(AyED::stack_exception& e)
	{
		std::cout << "Excepción de la clase 'stack_t': ";
		std::cout << e.what() <<  std::endl;
	}
	catch(exception& e)
	{
	    	std::cout << e.what() <<  std::endl;
	}
	

}

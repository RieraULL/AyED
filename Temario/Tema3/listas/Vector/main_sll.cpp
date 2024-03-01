#include <iostream>

#include "sll.hpp"
#include "memory.hpp"

#define N_CHARS 26

using namespace std;

int main(void)
{
	AyED::memory<char> memory;
	
	AyED::sll<char> lista(memory);

	for(int i{0}; i < N_CHARS; i++)
		lista.insert_head( memory.New('a' + i) );

	lista.write(cout);
	cout << endl;

	int nodo = lista.extract_head();
	char dato = memory[nodo].get_data();
	memory.Delete(nodo);

	cout << "Dato 1: " << dato << endl;

	nodo = lista.extract_head();
	dato = memory[nodo].get_data();
	memory.Delete(nodo);

	cout << "Dato 2: " << dato << endl;

	nodo = lista.extract_head();
	dato = memory[nodo].get_data();
	memory.Delete(nodo);

	cout << "Dato 3: " << dato << endl;

	lista.write(cout);
	cout << endl;
	
	nodo = lista.search('n');
	dato = memory[nodo].get_data();
	cout << "Dato 4: " << dato << endl; 
	
	nodo = lista.extract_after(nodo);
	memory.Delete(nodo);
	
	lista.write(cout);
	cout << endl;

	return 0;
}

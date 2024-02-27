#include <iostream>

#include "sll.hpp"

#define N_CHARS 26

using namespace std;

int main(void)
{
	AyED::sll<char> lista;

	for(int i = 0; i < N_CHARS; i++)
		lista.insert_head( new AyED::sll_node<char>('a' + i) );

	lista.write(cout);
	cout << endl;

	AyED::sll_node<char>* nodo = lista.extract_head();
	char dato = nodo->get_data();
	delete nodo;

	cout << "Dato 1: " << dato << endl;

	nodo = lista.extract_head();
	dato = nodo->get_data();
	delete nodo;

	cout << "Dato 2: " << dato << endl;

	nodo = lista.extract_head();
	dato = nodo->get_data();
	delete nodo;

	cout << "Dato 3: " << dato << endl;

	lista.write(cout);
	cout << endl;
	
	nodo = lista.search('n');
	dato = nodo->get_data();
	cout << "Dato 4: " << dato << endl; 
	
	nodo = lista.extract_after(nodo);
	delete nodo;
	
	lista.write(cout);
	cout << endl;	

	return 0;
}

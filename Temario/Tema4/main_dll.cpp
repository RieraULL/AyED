#include <iostream>

#include "dll.hpp"

#define N_CHARS 26

int main(void)
{
	AyED::dll_t<char> lista;

	for (int i = 0; i < N_CHARS; i++)
	{
		std::cout << "Introduciendo la letra: " << (char)('a' + i) << std::endl;
		lista.insert_head(new AyED::dll_node_t<char>('a' + i));
		lista.write(std::cout);
		std::cout << std::endl;
	}

	AyED::dll_node_t<char> *nodo = lista.extract_head();
	char dato = nodo->get_data();
	delete nodo;

	std::cout << "Extrae desde cabecera: " << dato << std::endl;

	nodo = lista.extract_head();
	dato = nodo->get_data();
	delete nodo;

	std::cout << "Extrae desde cabecera: " << dato << std::endl;

	nodo = lista.extract_tail();
	dato = nodo->get_data();
	delete nodo;

	std::cout << "Extrae desde cola: " << dato << std::endl;

	lista.write(std::cout);
	std::cout << std::endl;

	lista.remove(lista.get_head()->get_next()->get_next());

	lista.write(std::cout);
	std::cout << std::endl;

	nodo = lista.extract_tail();
	dato = nodo->get_data();
	delete nodo;

	std::cout << "Dato 5: " << dato << std::endl;

	lista.write(std::cout);
	std::cout << std::endl;

	nodo = lista.get_tail();
	dato = nodo->get_data();

	std::cout << "Por qué no lo elimina?: " << dato << std::endl;

	lista.write(std::cout);
	std::cout << std::endl;

	return 0;
}

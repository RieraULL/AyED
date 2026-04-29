#include "sll.hpp"
#include "stack_v.hpp"
#include "vector.hpp"
#include "matrix.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

// Procedimiento recursivo que recorre un vector de enteros desde la primera posicion (i = 0) hasta la ultima (i = n-1) y escribe su contenido por pantalla.
void write_vector_recursive(const AyED::vector &vec, int i)
{
    if (i == vec.size())
    {
    }
    else
    {
        cout << vec[i] << " ";
        write_vector_recursive(vec, i + 1);
    }
}

void write_vector_iterative(const AyED::vector &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

// procedimiento recursivo que recorre un vector de enteros desde la última posicion (i = n-1) hasta la primera (i = 0) y escribe su contenido por pantalla.
void write_vector_reverse_recursive(const AyED::vector &vec, int i)
{
    if (i == vec.size())
    {
    }
    else
    {
        write_vector_reverse_recursive(vec, i + 1);
        cout << vec[i] << " ";
    }
}

// procedimiento iterativo con pila que recorre un vector de enteros desde la última posicion (i = n-1) hasta la primera (i = 0) y escribe su contenido por pantalla.

void write_vector_reverse_iterative(const AyED::vector &vec)
{
    AyED::stack_v<int> s;

    for (int i = 0; i < vec.size(); i++)
    {
        s.push(vec[i]);
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

// procedimiento recursivo que recorre una lista simplemente enlazada de enteros desde la primera posicion (head) hasta la ultima (tail) y escribe su contenido por pantalla.
void write_list_recursive(AyED::sll_node<int> *node)
{
    if (node == NULL)
    {
    }
    else
    {
        cout << node->get_data() << " ";
        write_list_recursive(node->get_next());
    }
}

// procedimiento recursivo que recorre una lista simplemente enlazada de enteros desde la última posicion (tail) hasta la primera (head) y escribe su contenido por pantalla.
void write_list_reverse_recursive(AyED::sll_node<int> *node)
{
    if (node == NULL)
    {
    }
    else
    {
        write_list_reverse_recursive(node->get_next());
        cout << node->get_data() << " ";
    }
}

// procedimiento iterativo con pila que recorre una lista simplemente enlazada de enteros desde la última posicion (tail) hasta la primera (head) y escribe su contenido por pantalla.
void write_list_reverse_iterative(const AyED::sll<int> &L)
{
    AyED::stack_v<int> s;

    AyED::sll_node<int> *node = L.head();

    while (node != NULL)
    {
        s.push(node->get_data());
        node = node->get_next();
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

// procedimiento recursivo que recorre la fila i-ésima de una matriz de enteros desde la primera columna (j = 0) hasta la última (j = m-1) y escribe su contenido por pantalla.
void write_matrix_row_recursive(const AyED::matrix &M, int i, int j)
{
    if (j == M.get_n() + 1)
    {
    }
    else
    {
        cout << setw(5) << M(i, j) << " ";
        write_matrix_row_recursive(M, i, j + 1);
    }
}

// procedimiento recursivo que recorre la fila i-ésima de una matriz de enteros desde la última columna (j = m-1) hasta la primera (j = 0) y escribe su contenido por pantalla.
void write_matrix_row_reverse_recursive(const AyED::matrix &M,  int i, int j)
{
    if (j == M.get_n() + 1)
    {
    }
    else
    {
        write_matrix_row_reverse_recursive(M, i, j + 1);
        cout << setw(5) << M(i, j) << " ";
    }
}

// procedimiento recursivo que recorre la columna j-ésima de una matriz de enteros desde la primera fila (i = 0) hasta la última (i = n-1) y escribe su contenido por pantalla.
void write_matrix_column_recursive(const AyED::matrix &M, int i, int j)
{
    if (i == M.get_m() + 1)
    {
    }
    else
    {
        cout << setw(5) << M(i, j) << " ";
        write_matrix_column_recursive(M, i + 1, j);
    }
}

// procedimiento recursivo que recorre la columna j-ésima de una matriz de enteros desde la última fila (i = n-1) hasta la primera (i = 0) y escribe su contenido por pantalla.
void write_matrix_column_reverse_recursive(const AyED::matrix &M, int i, int j)
{
    if (i == M.get_m() + 1)
    {
    }
    else
    {
        write_matrix_column_reverse_recursive(M, i + 1, j);
        cout << setw(5) << M(i, j) << " ";
    }
}

// procedimiento recursivo que recorre toda una matriz de enteros de n filas y m columnas desde la primera fila (i = 0) hasta la última (i = n-1) y escribe su contenido por pantalla.
void write_matrix_recursive(const AyED::matrix &M, int i, int j)
{
    if (i == M.get_m() + 1)
    {
    }
    else
    {
        write_matrix_row_recursive(M, i, 1);
        cout << endl;
        write_matrix_recursive(M, i + 1, 1);
    }
}

// procedimiento recursivo que recorre toda una matriz de enteros de n filas y m columnas desde la última fila (i = n-1) hasta la primera (i = 0) y escribe su contenido por pantalla.
void write_matrix_reverse_recursive(const AyED::matrix &M, int i, int j)
{
    if (i == M.get_m() + 1)
    {
    }
    else
    {
        write_matrix_reverse_recursive(M, i + 1, 1);
        write_matrix_row_reverse_recursive(M, i, 1);
        cout << endl;
    }
}

int main()
{
    // Vectores

    AyED::vector v(5);

    for (size_t i{0}; i < v.size(); i++)
        v[i] = static_cast<int>(i + 1);

    cout << "Escribiendo el vector de forma recursiva:" << endl;
    write_vector_recursive(v, 0);
    cout << endl;

    cout << "Escribiendo el vector de forma iterativa:" << endl;
    write_vector_iterative(v);
    cout << endl;

    cout << "Escribiendo el vector de forma recursiva inversa:" << endl;
    write_vector_reverse_recursive(v, 0);
    cout << endl;

    cout << "Escribiendo el vector de forma iterativa inversa:" << endl;
    write_vector_reverse_iterative(v);
    cout << endl;

    cout << endl;
    // Listas simplemente enlazadas

    AyED::sll<int> L;

    for (size_t i{0}; i < 5; i++)
        L.insert_tail(new AyED::sll_node<int>(static_cast<int>(i + 1)));

    cout << "Escribiendo la lista de forma recursiva:" << endl;
    write_list_recursive(L.head());
    cout << endl;

    cout << "Escribiendo la lista de forma recursiva inversa:" << endl;
    write_list_reverse_recursive(L.head());
    cout << endl;

    cout << "Escribiendo la lista de forma iterativa inversa:" << endl;
    write_list_reverse_iterative(L);
    cout << endl;

    cout << endl;
    // Matrices

    AyED::matrix M(3, 4);

    for (size_t i{1}; i <= M.get_m(); i++)
    {
        for (size_t j{1}; j <= M.get_n(); j++)
        {
            M(i, j) = static_cast<int>(i * M.get_n() + j + 1);
        }
    }

    M.write(cout) << endl;

    cout << "Escribiendo la matriz de forma recursiva:" << endl;
    write_matrix_recursive(M, 1, 1);
    cout << endl;

    cout << "Escribiendo la matriz de forma recursiva inversa:" << endl;
    write_matrix_reverse_recursive(M, 1, 1);
    cout << endl;

    cout << "Escribiendo la fila 1 de la matriz de forma recursiva:" << endl;
    write_matrix_row_recursive(M, 1, 1);
    cout << endl;

    cout << "Escribiendo la columna 2 de la matriz de forma recursiva:" << endl;
    write_matrix_column_recursive(M, 1, 2);
    cout << endl;

    return 0;
}
#include <vector>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

const string digits = "0123456789ABCDEF";

ostream &write(ostream &os, const vector<int> &vec, int num_digits)
{
    for (size_t i = 0; i < num_digits; i++)
    {
        os << digits[vec[i]] << " ";
    }
    return os;
}

void generate_binary_recursive(vector<int> &x, int n, int i)
{
    if (i == n)
    {
        write(cout, x, n) << endl;
    }
    else
    {
        x[i] = 0;
        generate_binary_recursive(x, n, i + 1);

        x[i] = 1;
        generate_binary_recursive(x, n, i + 1);
    }
}

void generate_binary_pairs_recursive(vector<int> &x, int n, int i)
{
    if (i == n - 1)
    {
        write(cout, x, n - 1);
        cout << "0" << endl;
    }
    else
    {
        x[i] = 0;
        generate_binary_pairs_recursive(x, n, i + 1);

        x[i] = 1;
        generate_binary_pairs_recursive(x, n, i + 1);
    }
}

void generate_binary_pairs_recursive_bad(vector<int> &x, int n, int i)
{
    if (i == n)
    {
        if (x[n - 1] == 0)
        {
            write(cout, x, n) << endl;
        }
    }
    else
    {
        x[i] = 0;
        generate_binary_pairs_recursive(x, n, i + 1);

        x[i] = 1;
        generate_binary_pairs_recursive(x, n, i + 1);
    }
}

void generate_numbers_recursive(vector<int> &x, int n, int i, int base)
{
    if (i == n)
    {
        write(cout, x, n) << endl;
    }
    else
    {
        for (int digit = 0; digit < base; digit++)
        {
            x[i] = digit;
            generate_numbers_recursive(x, n, i + 1, base);
        }
    }
}

void write_subset(const vector<int> &values, const vector<int> &selected)
{
    cout << "{";
    bool first = true;

    for (size_t i = 0; i < values.size(); i++)
    {
        if (selected[i] == 1)
        {
            if (!first)
            {
                cout << ", ";
            }
            cout << values[i];
            first = false;
        }
    }

    cout << "}" << endl;
}

void generate_subsets_recursive(const vector<int> &values, vector<int> &selected, int i)
{
    if (i == static_cast<int>(values.size()))
    {
        write_subset(values, selected);
    }
    else
    {
        selected[i] = 0;
        generate_subsets_recursive(values, selected, i + 1);

        selected[i] = 1;
        generate_subsets_recursive(values, selected, i + 1);
    }
}

int main()
{
    int n = 3; // Cambia este valor para generar números binarios de diferente longitud
    vector<int> x(n);

    cout << "Generando números binarios de longitud " << n << ":" << endl;

    generate_binary_recursive(x, n, 0);

    cout << "Generando pares de números binarios de longitud " << n << ":" << endl;

    generate_binary_pairs_recursive(x, n, 0);

    cout << "Generando pares de números binarios de longitud " << n << " (método alternativo y muy malo):" << endl;

    generate_binary_pairs_recursive_bad(x, n, 0);

    cout << "Generando números en base " << 16 << ":" << endl;

    int base = 16; // Cambia este valor para generar números en diferentes bases
    generate_numbers_recursive(x, n - 1, 0, base);

    int base2 = 8; // Cambia este valor para generar números en diferentes bases
    cout << "Generando números en base " << base2 << ":" << endl;
    generate_numbers_recursive(x, n - 1, 0, base2);

    vector<int> conjunto = {1, 2, 3};
    vector<int> selected(conjunto.size(), 0);

    cout << "Generando subconjuntos de {1, 2, 3}:" << endl;
    generate_subsets_recursive(conjunto, selected, 0);

    return 0;
}
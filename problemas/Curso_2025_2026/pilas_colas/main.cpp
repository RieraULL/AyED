#include "graph_algorithms.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace AyED;
using namespace std;

namespace
{
	bool load_graph(const string& filename, grafo& g)
	{
		ifstream input(filename);
		if (!input)
		{
			cerr << "No se pudo abrir el fichero: " << filename << '\n';
			return false;
		}
		g.read(input);
		return true;
	}

	bool same_traverse(const vector<int>& got, const vector<int>& expected)
	{
		return got == expected;
	}

	void print_traverse(const vector<int>& traverse)
	{
		cout << "[";
		for (size_t i = 0; i < traverse.size(); ++i)
		{
			if (i > 0)
			{
				cout << ", ";
			}
			cout << traverse[i];
		}
		cout << "]";
	}

	bool run_bool_test(const string& test_name, bool got, bool expected)
	{
		const bool ok = (got == expected);
		cout << (ok ? "[PASS] " : "[FAIL] ") << test_name
			 << " -> obtenido=" << (got ? "true" : "false")
			 << ", esperado=" << (expected ? "true" : "false") << '\n';
		return ok;
	}

	bool run_int_test(const string& test_name, int got, int expected)
	{
		const bool ok = (got == expected);
		cout << (ok ? "[PASS] " : "[FAIL] ") << test_name
			 << " -> obtenido=" << got
			 << ", esperado=" << expected << '\n';
		return ok;
	}

	bool run_traverse_test(const string& test_name,
						   const vector<int>& got,
						   const vector<int>& expected)
	{
		const bool ok = same_traverse(got, expected);
		cout << (ok ? "[PASS] " : "[FAIL] ") << test_name << " -> obtenido=";
		print_traverse(got);
		cout << ", esperado=";
		print_traverse(expected);
		cout << '\n';
		return ok;
	}
}

int main()
{
	graph_algorithms algorithms;
	grafo g1, g2, g3;

	if (!load_graph("grafo1.txt", g1) ||
		!load_graph("grafo2.txt", g2) ||
		!load_graph("grafo3.txt", g3))
	{
		return 1;
	}

	int passed = 0;
	int total = 0;

	vector<int> bfs_g2;
	algorithms.bfs(g2, 0, bfs_g2);
	++total;
	passed += run_traverse_test("BFS en grafo2 (arbol enraizado en 0)",
								bfs_g2,
								{0, 1, 2, 3, 4, 5, 6, 7, 8, 9})
				  ? 1
				  : 0;

	vector<int> dfs_g2;
	algorithms.dfs(g2, 0, dfs_g2);
	++total;
	passed += run_traverse_test("DFS en grafo2 (pila iterativa)",
								dfs_g2,
								{0, 2, 6, 9, 5, 8, 1, 4, 7, 3})
				  ? 1
				  : 0;

	++total;
	passed += run_bool_test("is_connected en grafo1", algorithms.is_connected(g1), true)
				  ? 1
				  : 0;
	++total;
	passed += run_bool_test("is_connected en grafo2", algorithms.is_connected(g2), true)
				  ? 1
				  : 0;
	++total;
	passed += run_bool_test("is_connected en grafo3", algorithms.is_connected(g3), false)
				  ? 1
				  : 0;

	++total;
	passed += run_bool_test("has_cycle en grafo1", algorithms.has_cycle(g1), true)
				  ? 1
				  : 0;
	++total;
	passed += run_bool_test("has_cycle en grafo2", algorithms.has_cycle(g2), false)
				  ? 1
				  : 0;
	++total;
	passed += run_bool_test("has_cycle en grafo3", algorithms.has_cycle(g3), false)
				  ? 1
				  : 0;

	++total;
	passed += run_bool_test("has_path en grafo1 (0->4)", algorithms.has_path(g1, 0, 4), true)
				  ? 1
				  : 0;
	++total;
	passed += run_bool_test("has_path en grafo1 (4->0)", algorithms.has_path(g1, 4, 0), true)
				  ? 1
				  : 0;
	++total;
	passed += run_bool_test("has_path en grafo2 (0->9)", algorithms.has_path(g2, 0, 9), true)
				  ? 1
				  : 0;
	++total;
	passed += run_bool_test("has_path en grafo3 (0->5)", algorithms.has_path(g3, 0, 5), false)
				  ? 1
				  : 0;

	++total;
	passed += run_int_test("shortest_path en grafo2 (0->0)", algorithms.shortest_path(g2, 0, 0), 0)
				  ? 1
				  : 0;
	++total;
	passed += run_int_test("shortest_path en grafo2 (0->9)", algorithms.shortest_path(g2, 0, 9), 3)
				  ? 1
				  : 0;
	++total;
	passed += run_int_test("shortest_path en grafo1 (0->9)", algorithms.shortest_path(g1, 0, 9), 3)
				  ? 1
				  : 0;
	++total;
	passed += run_int_test("shortest_path en grafo3 (0->5)", algorithms.shortest_path(g3, 0, 5), -1)
				  ? 1
				  : 0;

	cout << '\n';
	cout << "Resumen: " << passed << "/" << total << " pruebas superadas.\n";

	return (passed == total) ? 0 : 2;
}

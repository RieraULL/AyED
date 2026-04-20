#pragma once

#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

namespace AyED
{

    class grafo
    {
    public:
        grafo(void);
        virtual ~grafo(void);

        ostream &write(std::ostream &os) const;
        istream &read(std::istream &is);

        const vector<int> &get_adyacentes(int vertex) const;
        const vector<int> &get_weights(int vertex) const;

        int n_vertices(void) const;
        int n_succesores(int vertex) const;

    private:
        vector<vector<int>> adyacencia_;
        vector<vector<int>> weights_;

    };
}
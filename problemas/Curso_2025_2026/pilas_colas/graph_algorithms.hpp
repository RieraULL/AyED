#pragma once

#include "grafo.hpp"

namespace AyED
{

    class graph_algorithms
    {
    public:
        void bfs(const grafo &g, int start, vector<int> &traverse) const;
        void dfs(const grafo &g, int start, vector<int> &traverse) const;

        bool is_connected(const grafo &g) const;
        bool has_cycle(const grafo &g) const;

    };
}
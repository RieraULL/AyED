#include "graph_algorithms.hpp"

#include <queue>
#include <stack>

using namespace std;

namespace AyED
{

    void graph_algorithms::bfs(const grafo &g, int start, vector<int> &traverse) const
    {
        queue<int> q;
        vector<bool> visited(g.n_vertices(), false);

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            traverse.push_back(vertex);

            for (int neighbor : g.get_adyacentes(vertex))
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

    void graph_algorithms::dfs(const grafo &g, int start, vector<int> &traverse) const
    {
        stack<int> s;
        vector<bool> visited(g.n_vertices(), false);

        s.push(start);
        visited[start] = true;

        while (!s.empty())
        {
            int vertex = s.top();
            s.pop();
            traverse.push_back(vertex);

            for (int neighbor : g.get_adyacentes(vertex))
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    s.push(neighbor);
                }
            }
        }
    }

    bool graph_algorithms::is_connected(const grafo &g) const
    {
        vector<int> traverse;
        bfs(g, 0, traverse);
        return traverse.size() == g.n_vertices();
    }

    bool graph_algorithms::has_path(const grafo &g, int start, int end) const
    {
        vector<int> traverse;
        bfs(g, start, traverse);
        
        for (int vertex : traverse)
        {
            if (vertex == end)
            {
                return true;
            }
        }
        return false;
    }

    int graph_algorithms::shortest_path(const grafo &g, int start, int end) const
    {
        if (start == end)
        {
            return 0;
        }

        queue<int> q;
        vector<int> distance(g.n_vertices(), -1);

        q.push(start);
        distance[start] = 0;

        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();

            for (int neighbor : g.get_adyacentes(vertex))
            {
                if (distance[neighbor] == -1)
                {
                    distance[neighbor] = distance[vertex] + 1;
                    
                    if (neighbor == end)
                    {
                        return distance[neighbor];
                    }
                    
                    q.push(neighbor);
                }
            }
        }
        return -1; // No path found
    }

    bool graph_algorithms::has_cycle(const grafo &g) const
    {
        vector<bool> visited(g.n_vertices(), false);
        vector<int> parent(g.n_vertices(), -1);

        for (int i = 0; i < g.n_vertices(); i++)
        {
            if (!visited[i])
            {
                stack<int> s;
                s.push(i);
                visited[i] = true;

                while (!s.empty())
                {
                    int vertex = s.top();
                    s.pop();

                    for (int neighbor : g.get_adyacentes(vertex))
                    {
                        if (!visited[neighbor])
                        {
                            visited[neighbor] = true;
                            parent[neighbor] = vertex;
                            s.push(neighbor);
                        }
                        else if (neighbor != parent[vertex])
                        {
                            return true; // Cycle detected
                        }
                    }
                }
            }
        }
        return false; // No cycle found
    }
}
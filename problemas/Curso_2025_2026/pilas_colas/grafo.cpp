#include "grafo.hpp"

namespace AyED
{

    grafo::grafo(void) : adyacencia_(), weights_()
    {
    }

    grafo::~grafo(void)
    {
    }

    int grafo::n_vertices(void) const
    {
        return adyacencia_.size();
    }

    int grafo::n_succesores(int vertex) const
    {
        assert(vertex >= 0 && vertex < static_cast<int>(adyacencia_.size()));
        return adyacencia_[vertex].size();
    }

    ostream &grafo::write(std::ostream &os) const
    {
        for (size_t i = 0; i < n_vertices(); i++)
        {
            os << "Vertice " << i << ": ";
            for (size_t j = 0; j < adyacencia_[i].size(); j++)
            {
                os << adyacencia_[i][j] << "(" << weights_[i][j] << ") ";
            }
            os << endl;
        }
        return os;
    }

    istream &grafo::read(std::istream &is)
    {
        int vertices, edges;
        is >> vertices >> edges;

        adyacencia_.resize(vertices);
        weights_.resize(vertices);

        for (int i = 0; i < edges; i++)
        {
            int u, v, w;
            is >> u >> v >> w;
            adyacencia_[u].push_back(v);
            weights_[u].push_back(w);
        }
        return is;
    }

    const vector<int> &grafo::get_adyacentes(int vertex) const
    {
        assert(vertex >= 0 && vertex < static_cast<int>(adyacencia_.size()));
        return adyacencia_[vertex];
    }

    const vector<int> &grafo::get_weights(int vertex) const
    {
        assert(vertex >= 0 && vertex < static_cast<int>(weights_.size()));
        return weights_[vertex];
    }
}
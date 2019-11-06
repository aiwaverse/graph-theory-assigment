#include "../include/graph.hpp"

Graph::Graph(int dim) {
    adjacency.resize(dim);
    for (auto& subv : adjacency) {
        subv.resize(dim);
        std::fill(subv.begin(), subv.end(), -2);
    }
}

int& Graph::operator()(int x, int y) {
    return adjacency.at(x).at(y);
}

std::ostream& operator<<(std::ostream& os, const Graph& rhs) {
    for (const auto& subv : rhs.adjacency) {
        for (const auto& elem : subv)
            os << elem;
        os << "\n";
    }
    return os;
}

#include "../include/graph.hpp"
#include <iostream>
#include <string>
#include <sstream>

Graph::Graph(int dim) {
    dimensions=dim;
    adjacency.resize(dim);
    int i{};
    for (auto& subv : adjacency) {
        subv.resize(dim);
        std::fill(subv.begin(), subv.end(), i);
        ++i;
    }
}

int& Graph::operator()(int x, int y) {
    return adjacency.at(x).at(y);
}

std::vector<int>& Graph::operator()(int x) {
    return adjacency.at(x);
}

std::ostream& operator<<(std::ostream& os, const Graph& rhs) {
    for (const auto& subv : rhs.adjacency) {
        for (const auto& elem : subv)
            os << "(" << elem << ")" << " ";
        os << "\n";
    }
    return os;
}

void Graph::read_keyboard_to_graph(void) {
    std::string input{};
    for (int i = 0; i < dimensions; ++i) {
        std::getline(std::cin, input);
        std::stringstream buffer(input);
        for (auto& elem : (*this)(i))
            buffer >> elem;
    }
}

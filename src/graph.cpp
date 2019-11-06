#include "../include/graph.hpp"
#include <iostream>
#include <sstream>
#include <string>

Graph::Graph(int dim) {
    dimensions = dim;
    adjacency.resize(dim);
    int i{};
    for (auto& subv : adjacency) {
        subv.resize(dim);
        std::fill(subv.begin(), subv.end(), i);
        ++i;
    }
}

int& Graph::operator()(int x, int y) {
    return adjacency[x][y];
}

std::vector<int>& Graph::operator()(int x) {
    return adjacency[x];
}

std::ostream& operator<<(std::ostream& os, const Graph& rhs) {
    for (const auto& subv : rhs.adjacency) {
        for (const auto& elem : subv)
            os << "(" << elem << ")"
               << " ";
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

std::vector<int> Graph::generate_msa(void) {
    std::vector<int> msa{};
    std::vector<int> to_search{0};
    int minimum{std::numeric_limits<int>::max()};
    int to_add{};
    for (int i{1}; i < dimensions; ++i) {   //the first vertice is the always the root
        minimum = std::numeric_limits<int>::max();
        for (const auto index : to_search) {
            for (int j{1}; j < dimensions; ++j) {
                auto curr = (*this)(index,j);   //same as this->operator()(index,j) or even adjacency.at(index).at(j)
                if ((curr < minimum) and (curr != -1)) {
                    if (std::find(to_search.begin(), to_search.end(), j) != to_search.end())    //if j is already on to_search, goes to next iteration
                        continue;
                    minimum = curr;
                    to_add = j;
                }
            }
        }
        msa.push_back(minimum);
        to_search.push_back(to_add);
    }
    return msa;
}

int Graph::minimum_biforest(void) {
    auto msa = generate_msa();
    // the minimum spanning biforest is just the minimum spanning tree minus the heaviest element
    return (std::accumulate(msa.begin(), msa.end(), 0) - *std::max_element(msa.begin(), msa.end()));
}

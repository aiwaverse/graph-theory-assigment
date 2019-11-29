#include "../include/graph.hpp"
#include <iostream>
#include <set>
#include <sstream>
#include <string>

// the single constructor
Graph::Graph(int dim) {
    if(dim < 0)
        throw std::runtime_error("Negative number of vertices\n");
    // this really does not work with a negative value
    dimensions = dim;
    adjacency.resize(dim);
    for (auto& subv : adjacency) {
        subv.resize(dim);
        // -2 for no good reason, it's an invalid number, made sense to me to start with invalid numbers
        std::fill(subv.begin(), subv.end(), -2);
    }
}

// to acess the numbers without too ugly syntax
int& Graph::operator()(int x, int y) {
    return adjacency[x][y];
}

// same idea but it gets a whole line
std::vector<int>& Graph::operator()(int x) {
    return adjacency[x];
}

// this isn't used on the final version, but it prints the graph (C++ style)
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
        std::stringstream buffer(input);  //i used a string stream to directly extract the numbers
        for (auto& elem : (*this)(i))
            buffer >> elem;
    }
}

// one can say this is basically the whole program
std::vector<int> Graph::generate_msa(void) {
    std::vector<int> msa{};
    // this basically is to avoid the wrong number bug
    if (dimensions == 0)
        return msa;
    std::set<int> to_search{0};  // i used a set to reduce find time, starts with the 0 index (first vertice)
    int minimum{std::numeric_limits<int>::max()};
    int to_add{};
    // will run dimensions-1 times
    for (int i{1}; i < dimensions; ++i) {  //the first vertice is the always the root
        minimum = std::numeric_limits<int>::max();
        // searchs on all lines available on to_search (ranged for)
        for (const auto index : to_search) {
            // runs the enterity of each of those lines
            for (int j{1}; j < dimensions; ++j) {
                auto curr = (*this)(index, j);  //same as this->operator()(index,j) or even adjacency.at(index).at(j)
                if ((curr < minimum) and (curr != -1)) {
                    if (to_search.find(j) != to_search.end())  //if j is already on to_search, goes to next iteration
                        continue;
                    // means the element is ready to be inserted (if no smaller is found)
                    minimum = curr;
                    to_add = j;
                }
            }
        }
        // msa will end as a vector of ints, since we're only bothering with values anyway
        msa.push_back(minimum);
        to_search.insert(to_add);
    }
    return msa;
}

// i think this one is self explicative
int Graph::minimum_biforest(void) {
    auto msa = generate_msa();
    // i got a bit paranoid with a possible bug, since the below code will fail for an empty graph (deferencing an iterator)
    if (msa.empty())
        return 0;
    // the minimum spanning biforest is just the minimum spanning tree minus the heaviest element
    return (std::accumulate(msa.begin(), msa.end(), 0) - *std::max_element(msa.begin(), msa.end()));
}

#pragma once
#include <algorithm>
#include <ostream>
#include <numeric>
#include <vector>

class Graph {
    friend std::ostream& operator<<(std::ostream& os, const Graph& rhs);

   private:
    int dimensions{};
    std::vector<std::vector<int>> adjacency{};
    std::vector<int> generate_msa(void);

   public:
    int& operator()(int, int);
    std::vector<int>& operator()(int);
    std::vector<int>& operator[](int i) { return this->operator()(i); };  //actually just to "look right", it just uses operator()(int)
    Graph(int dim);
    void read_keyboard_to_graph(void);
    int minimum_biforest(void);
};
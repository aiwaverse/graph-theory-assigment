#pragma once
#include <vector>
#include <algorithm>
#include <ostream>

class Graph{
  friend std::ostream& operator<<(std::ostream& os, const Graph& rhs);
  private:
    int dimensions{};
    std::vector<std::vector<int>> adjacency{};
  public:
    int& operator()(int, int);
    std::vector<int>& operator()(int);
    Graph(int dim);
    void read_keyboard_to_graph(void);
};
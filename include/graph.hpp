#include <vector>
#include <algorithm>
#include <ostream>

class Graph{
  friend std::ostream& operator<<(std::ostream& os, const Graph& rhs);
  private:
    std::vector<std::vector<int>> adjacency{};
  public:
    int& operator()(int x, int y);
    Graph(int dim);
};
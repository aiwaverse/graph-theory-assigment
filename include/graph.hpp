#include <vector>

class Graph{
  private:
    std::vector<std::vector<int>> adjacency{};
  public:
    int operator()(int x, int y);
};
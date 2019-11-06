#include "../include/graph.hpp"

int Graph::operator()(int x, int y){
    return adjacency.at(x).at(y);
}
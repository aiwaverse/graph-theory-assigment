#include "../include/graph.hpp"
#include <iostream>

int main(void){
    int size{};
    std::cin >> size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::ios::sync_with_stdio(false);   // i was scared at the possibility of a slow output
    // this adds the need to flush the stream to output to be displayed
    Graph measure(size);
    measure.read_keyboard_to_graph();
    std::cout << measure.minimum_biforest() << std::endl;
    return 0;
}
#include <iostream>
#include "../include/graph.hpp"

// Professor, eu se estiver lendo esse código, eu escrevo meus comentários em inglês, é costume de programação mesmo

int main(void) {
    int size{};
    // all these next lines do is read the size, and clear the buffer for the rest
    std::cin >> size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::ios::sync_with_stdio(false);  // i was scared at the possibility of a slow output
    // this adds the need to flush the stream to output to be displayed
    Graph measure(size);
    measure.read_keyboard_to_graph();
    std::cout << measure.minimum_biforest() << std::endl;
    return 0;
}
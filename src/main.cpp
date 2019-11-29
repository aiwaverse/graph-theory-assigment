#include <iostream>
#include "../include/graph.hpp"

// Professor, eu se estiver lendo esse código, eu escrevo meus comentários em inglês, é costume de programação mesmo

int main(void) {
    int size{};
    // all these next lines do is read the size, and clear the buffer for the rest
    std::cin >> size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    Graph measure(size);
    measure.read_keyboard_to_graph();
    std::cout << measure.minimum_biforest() << std::endl;
    return 0;
}
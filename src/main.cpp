#include "../include/graph.hpp"
#include <iostream>

int main(int argc, char* argv[]){
    int size{};
    
    if (argc != 2)      //TODO: after everything is done, remove this
        throw std::runtime_error("INVALID NUMBER OF ARGUMENTS\n");
    std::string wrapper(argv[1]);   //not gonna use c-strings
    size = std::stoi(wrapper);
    /*
    //TODO: this is to deal with input directly instead of arguments
    // uncomment it, and comment/delete the code above this to use it
    std::cin >> size;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    */
    std::ios::sync_with_stdio(false);   // i was scared at the possibility of a slow output
    // this adds the need to flush the stream to output to be displayed
    // good idea? idk
    Graph test(size);
    std::cout << "Please enter data:" << std::endl;
    test.read_keyboard_to_graph();
    std::cout << test;
    std::cout << test.minimum_biforest() << std::endl;
    return 0;
}
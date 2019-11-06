#include "../include/graph.hpp"
#include <iostream>

int main(void){
    std::ios::sync_with_stdio(false);   // i was scared at the possibility of a slow output
    Graph test(100);  
    std::cout << test;
    std::cout << std::flush;    // happens because of the sync with stdio,
                                // the stream needs to be flushed manually
    return 0;
}
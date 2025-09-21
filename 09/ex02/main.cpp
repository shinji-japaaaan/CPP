#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe pmerge;
    
    // Parse and validate input
    if (!pmerge.parseInput(argc, argv)) {
        return 1;
    }
    
    // Execute sorting and display results
    pmerge.execute();
    
    return 0;
}
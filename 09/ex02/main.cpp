#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

    // Before表示
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // vectorでソート
    clock_t start = clock();
    mergeInsertSort(vec);
    clock_t end = clock();
    double vecTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

    // dequeでソート
    start = clock();
    mergeInsertSort(deq);
    end = clock();
    double deqTime = double(end - start) / CLOCKS_PER_SEC * 1000000;

    // After表示
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector: " << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque: " << deqTime << " us" << std::endl;

    return 0;
}

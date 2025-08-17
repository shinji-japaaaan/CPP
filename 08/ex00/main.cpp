#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> numbers;
    for (int i = 0; i < 10; ++i) {
        numbers.push_back(i * 2); // 0, 2, 4, 6, 8, ...
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 6);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 7);
        std::cout << "Found: " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


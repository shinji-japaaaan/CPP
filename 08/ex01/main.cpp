#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main() {
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;

        // 大量追加テスト
        Span bigSpan(10000);
        std::vector<int> numbers;
        for (int i = 0; i < 10000; ++i)
            numbers.push_back(rand());
        bigSpan.addNumbers(numbers.begin(), numbers.end());
        std::cout << bigSpan.shortestSpan() << std::endl;
        std::cout << bigSpan.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

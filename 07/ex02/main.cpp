#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> emptyArr;
        std::cout << "emptyArr size: " << emptyArr.size() << std::endl;

        Array<int> intArr(5);
        for (unsigned int i = 0; i < intArr.size(); ++i)
            intArr[i] = i * 10;

        std::cout << "intArr contents: ";
        for (unsigned int i = 0; i < intArr.size(); ++i)
            std::cout << intArr[i] << " ";
        std::cout << std::endl;

        Array<int> copyArr = intArr;
        copyArr[0] = 999;

        std::cout << "After modifying copyArr[0]:\n";
        std::cout << "intArr[0]: " << intArr[0] << "\n";
        std::cout << "copyArr[0]: " << copyArr[0] << std::endl;

        std::cout << "Accessing out-of-bounds: " << std::endl;
        std::cout << intArr[100] << std::endl;  // should throw

    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

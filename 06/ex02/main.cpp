#include <iostream>
#include "Base.hpp"
#include "functions.hpp"

int main() {
    Base* obj = generate();

    std::cout << "Identify by pointer: ";
    identify(obj);

    std::cout << "Identify by reference: ";
    identify(*obj);

    delete obj;
    return 0;
}

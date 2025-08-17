#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data original;
    original.id = 42;
    original.name = "SerializedData";

    std::cout << "Original pointer:      " << &original << std::endl;
    std::cout << "Original.id:           " << original.id << std::endl;
    std::cout << "Original.name:         " << original.name << std::endl;

    unsigned long raw = Serializer::serialize(&original);
    std::cout << std::hex << raw << std::endl;
    Data* copy = Serializer::deserialize(raw);

    std::cout << "Deserialized pointer:  " << copy << std::endl;
    std::cout << "Copy.id:               " << copy->id << std::endl;
    std::cout << "Copy.name:             " << copy->name << std::endl;

    if (copy == &original)
        std::cout << "✅ Pointers match: serialization successful!" << std::endl;
    else
        std::cout << "❌ Pointers do not match: serialization failed!" << std::endl;

    return 0;
}

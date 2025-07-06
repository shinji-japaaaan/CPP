#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer {
private:
    Serializer(); // インスタンス化不可

public:
    static unsigned long serialize(Data* ptr);
    static Data* deserialize(unsigned long raw);
};

#endif

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
private:
    T* elements_;
    unsigned int size_;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);       // ← コピーコンストラクタ（直接実装）
    ~Array();

    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

#include "Array.tpp"

#endif

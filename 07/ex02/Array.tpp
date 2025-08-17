#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <cstdlib>

template <typename T>
Array<T>::Array() : elements_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : elements_(new T[n]), size_(n) {}

template <typename T>
Array<T>::Array(const Array& other) {
    size_ = other.size_;
    elements_ = new T[size_];
    for (unsigned int i = 0; i < size_; ++i) {
        elements_[i] = other.elements_[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] elements_;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] elements_;
        size_ = other.size_;
        elements_ = new T[size_];
        for (unsigned int i = 0; i < size_; ++i) {
            elements_[i] = other.elements_[i];
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= size_) {
        throw std::out_of_range("Index out of bounds");
    }
    return elements_[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return size_;
}

#endif

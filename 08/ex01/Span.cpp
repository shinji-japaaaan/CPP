#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span &other)
    : maxSize(other.maxSize), data(other.data) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        maxSize = other.maxSize;
        data = other.data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (data.size() >= maxSize)
        throw std::runtime_error("Span is full");
    data.push_back(num);
}

int Span::shortestSpan() const {
    if (data.size() < 2)
        throw std::runtime_error("Not enough numbers to find span");
    std::vector<int> sorted = data;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = sorted[1] - sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; ++i) {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (data.size() < 2)
        throw std::runtime_error("Not enough numbers to find span");
    std::vector<int>::const_iterator minIt = std::min_element(data.begin(), data.end());
    std::vector<int>::const_iterator maxIt = std::max_element(data.begin(), data.end());
    return *maxIt - *minIt;
}

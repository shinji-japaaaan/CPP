#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span {
private:
    unsigned int maxSize;
    std::vector<int> data;

public:
    explicit Span(unsigned int n);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int num);

    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        if (data.size() + std::distance(begin, end) > maxSize)
            throw std::runtime_error("Span is full");
        data.insert(data.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
};

#endif

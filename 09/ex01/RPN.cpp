#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

RPN::RPN() {}
RPN::RPN(const RPN& other) { *this = other; }
RPN& RPN::operator=(const RPN& other) {
    (void)other;
    return *this;
}
RPN::~RPN() {}

int RPN::evaluate(const std::string& expr) {
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && std::string("+-*/").find(token) != std::string::npos) {
            if (values.size() < 2)
                throw std::runtime_error("Error");
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            int result = 0;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Error");
                result = a / b;
            }
            values.push(result);
        } else {
            // 数字のチェック
            if (token.size() != 1 || !isdigit(token[0]))
                throw std::runtime_error("Error");
            int num = token[0] - '0';
            values.push(num);
        }
    }

    if (values.size() != 1)
        throw std::runtime_error("Error");
    return values.top();
}

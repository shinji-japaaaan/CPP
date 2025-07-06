#!/bin/bash

# 正しくディレクトリ名を指定
DIR="./ex00"

# ディレクトリ作成
mkdir -p "$DIR"

# whatever.hpp 作成
cat << 'EOF' > "$DIR/whatever.hpp"
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const& min(T const& a, T const& b) {
	return (a < b ? a : b);
}

template <typename T>
T const& max(T const& a, T const& b) {
	return (a > b ? a : b);
}

#endif
EOF

# main.cpp 作成
cat << 'EOF' > "$DIR/main.cpp"
#include <iostream>
#include <string>
#include "whatever.hpp"

int main(void) {
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

	return 0;
}
EOF

# Makefile 作成
cat << 'EOF' > "$DIR/Makefile"
NAME = whatever

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = \$(SRC:.cpp=.o)

all: \$(NAME)

\$(NAME): \$(OBJ)
	\$(CXX) \$(CXXFLAGS) -o \$(NAME) \$(OBJ)

clean:
	rm -f \$(OBJ)

fclean: clean
	rm -f \$(NAME)

re: fclean all
EOF

echo "✅ ex00 ディレクトリとファイルを作成しました。"

#include <iostream>
#include <string>
#include "iter.hpp"

// 非const用の関数テンプレート
template <typename T>
void increment(T& x) {
	x += 1;
}

// constでも使える関数テンプレート
template <typename T>
void printElement(const T& x) {
	std::cout << x << std::endl;
}

int main() {
	int intArr[] = {1, 2, 3, 4, 5};
	std::size_t intLen = sizeof(intArr) / sizeof(intArr[0]);

	std::cout << "Before increment:" << std::endl;
	iter(intArr, intLen, printElement<int>);  // ★ 明示的に型を指定

	iter(intArr, intLen, increment<int>);     // ★ 明示的に型を指定

	std::cout << "After increment:" << std::endl;
	iter(intArr, intLen, printElement<int>);  // ★

	std::string strArr[] = {"Hello", "42", "Tokyo"};
	std::size_t strLen = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "String array:" << std::endl;
	iter(strArr, strLen, printElement<std::string>);  // ★ 文字列型も明示
}

#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <ctime>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	// -------------------- vector用 --------------------
	clock_t startVec = clock();

	std::vector<int> vec;
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num) || num <= 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		vec.push_back(num);
	}

	fordJohnsonSort(vec);

	clock_t endVec = clock();
	double vecTime = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	// -------------------- deque用 --------------------
	clock_t startDeq = clock();

	std::deque<int> deq;
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num) || num <= 0)
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}
		deq.push_back(num);
	}

	fordJohnsonSort(deq);

	clock_t endDeq = clock();
	double deqTime = double(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	// -------------------- Before / After 表示 --------------------
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector: " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque: " << deqTime << " us" << std::endl;

	return 0;
}

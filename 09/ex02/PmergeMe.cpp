#include "PmergeMe.hpp"
#include <algorithm>

// -------------------- Vector用 --------------------
void fordJohnsonSort(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<int> large, small;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
		{
			large.push_back(vec[i]);
			small.push_back(vec[i + 1]);
		}
		else
		{
			large.push_back(vec[i + 1]);
			small.push_back(vec[i]);
		}
	}
	if (vec.size() % 2 != 0)
		small.push_back(vec.back());

	fordJohnsonSort(large);

	std::vector<int> sorted;
	sorted.reserve(vec.size());
	for (size_t i = 0; i < large.size(); ++i)
		sorted.push_back(large[i]);

	for (size_t i = 0; i < small.size(); ++i)
	{
		std::vector<int>::iterator it =
			std::lower_bound(sorted.begin(), sorted.end(), small[i]);
		sorted.insert(it, small[i]);
	}

	vec = sorted;
}

// -------------------- Deque用 --------------------
void fordJohnsonSort(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::deque<int> large, small;
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
		{
			large.push_back(deq[i]);
			small.push_back(deq[i + 1]);
		}
		else
		{
			large.push_back(deq[i + 1]);
			small.push_back(deq[i]);
		}
	}
	if (deq.size() % 2 != 0)
		small.push_back(deq.back());

	fordJohnsonSort(large);

	std::deque<int> sorted;
	for (size_t i = 0; i < large.size(); ++i)
		sorted.push_back(large[i]);

	for (size_t i = 0; i < small.size(); ++i)
	{
		std::deque<int>::iterator it =
			std::lower_bound(sorted.begin(), sorted.end(), small[i]);
		sorted.insert(it, small[i]);
	}

	deq = sorted;
}

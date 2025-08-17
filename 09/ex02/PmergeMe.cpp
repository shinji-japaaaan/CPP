#include "PmergeMe.hpp"

// 基本的な Ford-Johnson マージ挿入法（簡略版）
// 本格的に最適化すると複雑になるため簡略化
template<typename T>
void mergeInsertSort(T& container) {
    if (container.size() <= 1) return;

    typename T::iterator mid = container.begin() + container.size() / 2;
    T left(container.begin(), mid);
    T right(mid, container.end());

    mergeInsertSort(left);
    mergeInsertSort(right);

    // マージ
    typename T::iterator it = container.begin();
    typename T::iterator lIt = left.begin();
    typename T::iterator rIt = right.begin();

    while (lIt != left.end() && rIt != right.end()) {
        if (*lIt <= *rIt) {
            *it = *lIt;
            ++lIt;
        } else {
            *it = *rIt;
            ++rIt;
        }
        ++it;
    }

    while (lIt != left.end()) {
        *it = *lIt;
        ++lIt;
        ++it;
    }

    while (rIt != right.end()) {
        *it = *rIt;
        ++rIt;
        ++it;
    }
}

// 明示的インスタンス化
template void mergeInsertSort<std::vector<int> >(std::vector<int>&);
template void mergeInsertSort<std::deque<int> >(std::deque<int>&);
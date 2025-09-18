#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

// ------------------------ Jacobstahl 配列 ------------------------
const size_t Jacobsthal[] = {1, 3, 5, 11, 21, 43, 85, 171, 341, 683,
                                    1365, 2731, 5461, 10923, 21845, 43691,
                                    87381, 174763, 349525, 699051, 1398101,
                                    2796203, 5592405, 11184811, 22369621,
                                    44739243, 89478485, 178956971, 357913941,
                                    715827883, 1431655765};

// ------------------------ 比較用ファンクタ ------------------------
struct PairCompare {
    bool operator()(const std::pair<int,int> &x, const std::pair<int,int> &y) const {
        return x.second < y.second;
    }
};

// ------------------------ 内部ユーティリティ ------------------------
void binarySearchInsertVec(std::vector<int> &mainChain,
                                  std::vector<int>::iterator end, int val) {
    std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), end, val);
    mainChain.insert(it, val);
}

void binarySearchInsertDeq(std::deque<int> &mainChain,
                                  std::deque<int>::iterator end, int val) {
    std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), end, val);
    mainChain.insert(it, val);
}

// ------------------------ Ford–Johnson ソート (vector用) ------------------------
void fordJohnsonSortVec(std::vector<int> &input) {
    if (input.size() <= 1) return;

    typedef std::pair<int,int> Pair;
    std::vector<Pair> pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i], b = input[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(Pair(a,b));
    }

    int additional = -1;
    if (input.size() % 2 == 1) additional = input.back();

    std::sort(pairs.begin(), pairs.end(), PairCompare());

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].second);
    if (!pairs.empty()) mainChain.insert(mainChain.begin(), pairs[0].first);

    size_t jacobIdx = 1;
    std::vector<Pair>::iterator lastJacobIt = pairs.begin();

    while (Jacobsthal[jacobIdx] <= pairs.size()) {
        std::vector<Pair>::iterator pairIt = pairs.begin() + (Jacobsthal[jacobIdx] - 1);
        lastJacobIt = pairIt;
        int inserted = 0;
        while (Jacobsthal[jacobIdx] - inserted > Jacobsthal[jacobIdx-1]) {
            std::vector<int>::iterator sliceEnd = 
                std::find(mainChain.begin(), mainChain.end(), pairIt->second);
            binarySearchInsertVec(mainChain, sliceEnd, pairIt->first);
            --pairIt;
            ++inserted;
        }
        ++jacobIdx;
    }

    if (Jacobsthal[jacobIdx-1] != pairs.size()) {
        std::vector<Pair>::iterator pairIt = pairs.end();
        if (pairIt != pairs.begin()) --pairIt;
        while (pairIt != lastJacobIt) {
            std::vector<int>::iterator sliceEnd = 
                std::find(mainChain.begin(), mainChain.end(), pairIt->second);
            binarySearchInsertVec(mainChain, sliceEnd, pairIt->first);
            --pairIt;
        }
    }

    if (additional != -1) binarySearchInsertVec(mainChain, mainChain.end(), additional);

    size_t idx = 0;
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it, ++idx) {
        *it = mainChain[idx];
    }
}

// ------------------------ Ford–Johnson ソート (deque用) ------------------------
void fordJohnsonSortDeq(std::deque<int> &input) {
    if (input.size() <= 1) return;

    typedef std::pair<int,int> Pair;
    std::vector<Pair> pairs;

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i], b = input[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(Pair(a,b));
    }

    int additional = -1;
    if (input.size() % 2 == 1) additional = input.back();

    std::sort(pairs.begin(), pairs.end(), PairCompare());

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i) mainChain.push_back(pairs[i].second);
    if (!pairs.empty()) mainChain.push_front(pairs[0].first);

    size_t jacobIdx = 1;
    std::vector<Pair>::iterator lastJacobIt = pairs.begin();

    while (Jacobsthal[jacobIdx] <= pairs.size()) {
        std::vector<Pair>::iterator pairIt = pairs.begin() + (Jacobsthal[jacobIdx] - 1);
        lastJacobIt = pairIt;
        int inserted = 0;
        while (Jacobsthal[jacobIdx] - inserted > Jacobsthal[jacobIdx-1]) {
            std::deque<int>::iterator sliceEnd = 
                std::find(mainChain.begin(), mainChain.end(), pairIt->second);
            binarySearchInsertDeq(mainChain, sliceEnd, pairIt->first);
            --pairIt;
            ++inserted;
        }
        ++jacobIdx;
    }

    if (Jacobsthal[jacobIdx-1] != pairs.size()) {
        std::vector<Pair>::iterator pairIt = pairs.end();
        if (pairIt != pairs.begin()) --pairIt;
        while (pairIt != lastJacobIt) {
            std::deque<int>::iterator sliceEnd = 
                std::find(mainChain.begin(), mainChain.end(), pairIt->second);
            binarySearchInsertDeq(mainChain, sliceEnd, pairIt->first);
            --pairIt;
        }
    }

    if (additional != -1) binarySearchInsertDeq(mainChain, mainChain.end(), additional);

    size_t idx = 0;
    for (std::deque<int>::iterator it = input.begin(); it != input.end(); ++it, ++idx) {
        *it = mainChain[idx];
    }
}

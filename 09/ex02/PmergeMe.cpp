#include "PmergeMe.hpp"
#include <set>

// Orthodox Canonical Form implementation
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _inputData(other._inputData) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _inputData = other._inputData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

// Utility function to check if string represents a valid positive integer
bool PmergeMe::isValidNumber(const std::string& str) const {
    if (str.empty()) return false;

    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (*it < '0' || *it > '9') return false;
    }

    if (str.length() > 1 && str[0] == '0') return false;
    return true;
}

// Get current time in microseconds
double PmergeMe::getTimeInMicroseconds() const {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}

// Generate Jacobsthal sequence
std::vector<int> PmergeMe::generateJacobsthalSequence(int n) const {
    std::vector<int> jacobsthal;
    if (n <= 0) return jacobsthal;

    jacobsthal.push_back(1);
    if (n == 1) return jacobsthal;

    jacobsthal.push_back(1);
    int a = 1, b = 1;
    while (true) {
        int next = b + 2 * a;
        if (next > n) break;
        jacobsthal.push_back(next);
        a = b;
        b = next;
    }
    return jacobsthal;
}

// Generate insertion order based on Jacobsthal sequence
std::vector<int> PmergeMe::generateInsertionOrder(int n) const {
    std::vector<int> jacobsthal = generateJacobsthalSequence(n);
    std::vector<int> order;

    int last = 0;
    for (std::vector<int>::size_type i = 1; i < jacobsthal.size(); ++i) {
        int current = jacobsthal[i];
        int limit = (current < n) ? current : n;
        for (int j = limit; j > last; --j) {
            order.push_back(j - 1);
        }
        last = current;
    }
    for (int j = n; j > last; --j) {
        order.push_back(j - 1);
    }
    return order;
}

// Binary search for vector
int PmergeMe::binarySearchVector(const std::vector<int>& vec,
                                 int value, int left, int right) const {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] <= value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

// Binary search for deque
int PmergeMe::binarySearchDeque(const std::deque<int>& deq,
                                int value, int left, int right) const {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (deq[mid] <= value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

// Ford-Johnson algorithm for vector
std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int>& arr) const {
    std::vector<int> result = arr;
    int n = result.size();

    if (n <= 1) return result;
    if (n == 2) {
        if (result[0] > result[1]) std::swap(result[0], result[1]);
        return result;
    }

    // Step 1: Create pairs and separate larger/smaller elements
    std::vector<std::pair<int,int> > pairs;
    std::vector<int> larger, smaller;

    int i = 0;
    for (; i + 1 < n; i += 2) {
        if (result[i] > result[i + 1]) {
            pairs.push_back(std::make_pair(result[i], result[i + 1]));
            larger.push_back(result[i]);
            smaller.push_back(result[i + 1]);
        } else {
            pairs.push_back(std::make_pair(result[i + 1], result[i]));
            larger.push_back(result[i + 1]);
            smaller.push_back(result[i]);
        }
    }
    if (i < n) { // 余りは smaller に追加
        smaller.push_back(result[i]);
    }

    // Step 2: Recursively sort larger elements
    std::vector<int> mainChain;
    if (larger.size() > 1) mainChain = fordJohnsonVector(larger);
    else if (larger.size() == 1) mainChain = larger;

    // Reorder smaller elements according to sorted larger elements
    std::vector<int> pend;
    for (std::vector<int>::size_type k = 0; k < mainChain.size(); ++k) {
        int largeVal = mainChain[k];
        for (std::vector<std::pair<int,int> >::size_type j = 0;
             j < pairs.size(); ++j) {
            if (pairs[j].first == largeVal) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
    // ペアに属さない余りも pend に入る
    if (smaller.size() > pend.size()) {
        pend.push_back(smaller.back());
    }

    // Step 3: Build result with strategic insertion
    std::vector<int> finalResult;
    if (!pend.empty() && !mainChain.empty()) {
        finalResult.push_back(pend[0]);
        finalResult.push_back(mainChain[0]);
    }
    for (std::vector<int>::size_type k = 1; k < mainChain.size(); ++k) {
        finalResult.push_back(mainChain[k]);
    }

    if (pend.size() > 1) {
		// pend.size() を渡す
		std::vector<int> order = generateInsertionOrder(pend.size());

		// 先頭の 0 を削除
		if (!order.empty()) {
			order.erase(order.begin());
		}

		for (size_t k = 0; k < order.size(); ++k) {
			int idx = order[k];  // actualIdx = idx のまま使う
			if (idx < (int)pend.size()) {
				int val = pend[idx];
				int limitPos = finalResult.size();

				if (idx < (int)mainChain.size()) {
					for (size_t m = 0; m < finalResult.size(); ++m) {
						if (finalResult[m] == mainChain[idx]) {
							limitPos = m;
							break;
						}
					}
				}

				int pos = binarySearchVector(finalResult, val, 0, limitPos - 1);
				finalResult.insert(finalResult.begin() + pos, val);
			}
		}
	}
    return finalResult;
}

// Ford-Johnson algorithm for deque
std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int>& arr) const {
    std::deque<int> result = arr;
    int n = result.size();

    if (n <= 1) return result;
    if (n == 2) {
        if (result[0] > result[1]) std::swap(result[0], result[1]);
        return result;
    }

    // Step 1
    std::deque<std::pair<int,int> > pairs;
    std::deque<int> larger, smaller;

    int i = 0;
    for (; i + 1 < n; i += 2) {
        if (result[i] > result[i + 1]) {
            pairs.push_back(std::make_pair(result[i], result[i + 1]));
            larger.push_back(result[i]);
            smaller.push_back(result[i + 1]);
        } else {
            pairs.push_back(std::make_pair(result[i + 1], result[i]));
            larger.push_back(result[i + 1]);
            smaller.push_back(result[i]);
        }
    }
    if (i < n) { // 余りは smaller に追加
        smaller.push_back(result[i]);
    }

    // Step 2
    std::deque<int> mainChain;
    if (larger.size() > 1) mainChain = fordJohnsonDeque(larger);
    else if (larger.size() == 1) mainChain = larger;

    // Reorder smaller
    std::deque<int> pend;
    for (std::deque<int>::size_type k = 0; k < mainChain.size(); ++k) {
        int largeVal = mainChain[k];
        for (std::deque<std::pair<int,int> >::size_type j = 0;
             j < pairs.size(); ++j) {
            if (pairs[j].first == largeVal) {
                pend.push_back(pairs[j].second);
                break;
            }
        }
    }
    if (smaller.size() > pend.size()) {
        pend.push_back(smaller.back());
    }

    // Step 3
    std::deque<int> finalResult;
    if (!pend.empty() && !mainChain.empty()) {
        finalResult.push_back(pend[0]);
        finalResult.push_back(mainChain[0]);
    }
    for (std::deque<int>::size_type k = 1; k < mainChain.size(); ++k) {
        finalResult.push_back(mainChain[k]);
    }

    if (pend.size() > 1) {
        // vector 版と同じように Jacobsthal 挿入順序を生成
        std::vector<int> order = generateInsertionOrder(pend.size());
        
        if (!order.empty()) order.erase(order.begin());

        for (size_t k = 0; k < order.size(); ++k) {
            int idx = order[k];
            if (idx < (int)pend.size()) {
                int val = pend[idx];
                int limitPos = finalResult.size();

                if (idx < (int)mainChain.size()) {
                    for (size_t m = 0; m < finalResult.size(); ++m) {
                        if (finalResult[m] == mainChain[idx]) {
                            limitPos = m;
                            break;
                        }
                    }
                }

                int pos = binarySearchDeque(finalResult, val, 0, limitPos - 1);
                finalResult.insert(finalResult.begin() + pos, val);
            }
        }
    }
    return finalResult;
}

// Parse command line input
bool PmergeMe::parseInput(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return false;
    }

    _inputData.clear();
    std::set<int> seen;  // 重複チェック用

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (!isValidNumber(arg)) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        std::istringstream iss(arg);
        int num; 
        iss >> num;
        if (iss.fail() || num <= 0) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        // 重複チェック
        if (seen.find(num) != seen.end()) {
            std::cerr << "Error" << num << std::endl;
            return false;
        }
        seen.insert(num);

        _inputData.push_back(num);
    }
    return true;
}

void PmergeMe::execute() {
    std::cout << "Before:";
    for (std::vector<int>::size_type i = 0; i < _inputData.size(); ++i) {
        std::cout << " " << _inputData[i];
    }
    std::cout << std::endl;

    // ===== ベンチマーク開始 =====
    double startVector = getTimeInMicroseconds();
    std::vector<int> dataVector = _inputData;          // コピーも含める
    std::vector<int> sortedVector = fordJohnsonVector(dataVector);
    double endVector = getTimeInMicroseconds();

    double startDeque = getTimeInMicroseconds();
    std::deque<int> dataDeque(_inputData.begin(), _inputData.end()); // コピー含む
    std::deque<int> sortedDeque = fordJohnsonDeque(dataDeque);
    double endDeque = getTimeInMicroseconds();
    // ===== ベンチマーク終了 =====

    std::cout << "After:";
    for (std::vector<int>::size_type i = 0; i < sortedVector.size(); ++i) {
        std::cout << " " << sortedVector[i];
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _inputData.size()
              << " elements with std::vector : "
              << (endVector - startVector) << " us\n";
    std::cout << "Time to process a range of " << _inputData.size()
              << " elements with std::deque  : "
              << (endDeque - startDeque) << " us\n";
}


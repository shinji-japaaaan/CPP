#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

// デフォルトコンストラクタ
BitcoinExchange::BitcoinExchange() : priceMap() {}

// コピーコンストラクタ
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : priceMap(other.priceMap) {}

// コピー代入演算子
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        priceMap = other.priceMap;
    }
    return *this;
}

// デストラクタ
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::loadPriceDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str()); // c_str()を使う
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line); // ヘッダー読み飛ばし

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        std::string priceStr;

        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, priceStr))
            continue;

        double price = 0.0;
        std::stringstream ssPrice(priceStr);
        ssPrice >> price;
        if (ssPrice.fail())
            continue;

        priceMap[date] = price;
    }
    return true;
}

double BitcoinExchange::getPriceForDate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = priceMap.lower_bound(date);

    // 完全一致した場合
    if (it != priceMap.end() && it->first == date) {
        return it->second;
    }

    // すべてのデータよりも前の日付だった場合
    if (it == priceMap.begin()) {
        return -1.0;  // データなしを示す
    }

    // すべてのデータよりも後の日付だった場合
    if (it == priceMap.end()) {
        --it;  // 最後の要素に移動
        return it->second;
    }

    // 途中の日付の場合 → 直前の要素を返す
    --it;
    return it->second;
}

